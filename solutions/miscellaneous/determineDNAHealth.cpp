#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


class Vertex{

public:
Vertex()
{
//        Children = new Hashtable();
        Leaf = false;
        Parent = -1;
        SuffixLink = -1;
        //WordID = -1;
        EndWordLink= -1;
        //val = -1;
}

~Vertex()
{
    //dtor
}

        // Links to the child vertexes in the trie:
        // Key: A single character
        // Value: The ID of vertex
        map<char, int> Children;

        // Flag that some word from the dictionary ends in this vertex
        bool Leaf;

        // Link to the parent vertex
        int Parent;

        // Char which moves us from the parent vertex to the current vertex
        char ParentChar;

        // Suffix link from current vertex (the equivalent of P[i] from the KMP algorithm)
        int SuffixLink;

        // Link to the leaf vertex of the maximum-length word we can make from the current prefix
        int EndWordLink;

        // If the vertex is the leaf, we store the ID of the word
        vector<int> WordID;
        vector<int> HealthValue;

};

class Aho
{

public:
    Aho()
    {
        //ctor
        size = 0;
        root = 0;
                Init();

    }

    ~Aho()
    {
        //Trie = new List<Vertex>();
    //        WordsLength = new List<int>();
    }

    void Init()
    {
        Vertex v;
        Trie.push_back(v);
        size++;
                            //cout << Trie[0].Parent << endl;

    }

    void AddString(string s, int wordID, int val)
    {
        int curVertex = root;

        for (int i = 0; i < s.size(); ++i) // Iterating over the string's characters
        {
            char c = s[i];

            // Checking if a vertex with this edge exists in the trie:
            //Trie[curVertex].Children['c'] = 1;
            if (Trie[curVertex].Children.count(c) == 0)
            {
            //cout << Trie[curVertex].Children['c'];

                Vertex v;
                Trie.push_back(v);

                Trie[size].SuffixLink = -1; // If not - add vertex
                Trie[size].Parent = curVertex;
                Trie[size].ParentChar = c;
                Trie[curVertex].Children[c] = size;
                size++;
            }

            curVertex = (int)Trie[curVertex].Children[c]; // Move to the new vertex in the trie
        }
        // Mark the end of the word and store its ID
        Trie[curVertex].Leaf = true;
        Trie[curVertex].WordID.push_back(wordID);
        Trie[curVertex].HealthValue.push_back(val);
        WordsLength.push_back(s.size());
    }

    void PrepareAho()
    {
        queue<int> vertexQueue;// = new queue<int>();
        vertexQueue.push(root);
        while (vertexQueue.size() > 0)
        {
            int curVertex = vertexQueue.front();
            vertexQueue.pop();
            CalcSuffLink(curVertex);

            for (std::map<char,int>::iterator it= Trie[curVertex].Children.begin(); it!= Trie[curVertex].Children.end(); ++it)// (char key in Trie[curVertex].Children.Keys)
            {
                vertexQueue.push(it->second);
            }
        }
    }

    void CalcSuffLink(int vertex)
    {
        // Processing root (empty string)
        if (vertex == root)
        {
            Trie[vertex].SuffixLink = root;
            Trie[vertex].EndWordLink = root;
            return;
        }
        // Processing children of the root (one character substrings)
        if (Trie[vertex].Parent == root)
        {
            Trie[vertex].SuffixLink = root;
            if (Trie[vertex].Leaf) Trie[vertex].EndWordLink = vertex;
            else Trie[vertex].EndWordLink = Trie[Trie[vertex].SuffixLink].EndWordLink;
            return;
        }
        // Cases above are degenerate cases as for prefix function calculation; the
        // value is always 0 and links to the root vertex.

        // To calculate the suffix link for the current vertex, we need the suffix
        // link for the parent of the vertex and the character that moved us to the
        // current vertex.
        int curBetterVertex = Trie[Trie[vertex].Parent].SuffixLink;
        char chVertex = Trie[vertex].ParentChar;
        // From this vertex and its substring we will start to look for the maximum
        // prefix for the current vertex and its substring.

        while (true)
        {
            // If there is an edge with the needed char, we update our suffix link
            // and leave the cycle
            if (Trie[curBetterVertex].Children.count(chVertex) == 1)
            {
                    Trie[vertex].SuffixLink = (int)Trie[curBetterVertex].Children[chVertex];
                    break;
            }
            // Otherwise, we are jumping by suffix links until we reach the root
            // (equivalent of k == 0 in prefix function calculation) or we find a
            // better prefix for the current substring.
            if (curBetterVertex == root)
            {
                    Trie[vertex].SuffixLink = root;
                    break;
            }
            curBetterVertex = Trie[curBetterVertex].SuffixLink; // Go back by sufflink
        }
        // When we complete the calculation of the suffix link for the current
        // vertex, we should update the link to the end of the maximum length word
        // that can be produced from the current substring.
        if (Trie[vertex].Leaf) Trie[vertex].EndWordLink = vertex;
        else Trie[vertex].EndWordLink = Trie[Trie[vertex].SuffixLink].EndWordLink;
    }

    unsigned long long ProcessString(string text, int start, int endindex)
    {
        // Current state value
        int currentState = root;

    //    this.start = start;
        //this.endindex = endindex;
        // Targeted result value
        unsigned long long result = 0;

        for (int j = 0; j < text.size(); j++)
        {
            // Calculating new state in the trie
            while (true)
            {
                // If we have the edge, then use it
                if (Trie[currentState].Children.count(text[j]) == 1)
                {
                    currentState = (int)Trie[currentState].Children[text[j]];
                    break;
                }
                // Otherwise, jump by suffix links and try to find the edge with
                // this char

                // If there aren't any possible edges we will eventually ascend to
                // the root, and at this point we stop checking.
                if (currentState == root) break;
                currentState = Trie[currentState].SuffixLink;
            }
            int checkState = currentState;

            // Trying to find all possible words from this prefix
            while (true)
            {
                // Checking all words that we can get from the current prefix
                checkState = Trie[checkState].EndWordLink;

                // If we are in the root vertex, there are no more matches
                if (checkState == root) break;

                // If the algorithm arrived at this row, it means we have found a
                // pattern match. And we can make additional calculations like find
                // the index of the found match in the text. Or check that the found
                // pattern is a separate word and not just, e.g., a substring.

                for(int i = 0; i < Trie[checkState].HealthValue.size(); i++){
                        if(Trie[checkState].WordID[i]>= start && Trie[checkState].WordID[i]<=endindex)
                        {
                            result += Trie[checkState].HealthValue[i];//++;
                        }
                }
                int indexOfMatch = j + 1 - WordsLength[Trie[checkState].WordID[0]];

                // Trying to find all matched patterns of smaller length
                checkState = Trie[checkState].SuffixLink;
            }
        }

        return result;
    }
private:
        vector<Vertex> Trie;
        vector<int> WordsLength;
        int size;
        int root;
        int start;
        int endindex;

};
int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string genes_temp_temp;
    getline(cin, genes_temp_temp);

    vector<string> genes_temp = split_string(genes_temp_temp);

    vector<string> genes(n);
   // map<string, vector<int>> genes_val;

    for (int i = 0; i < n; i++) {
        string genes_item = genes_temp[i];

        genes[i] = genes_item;
    }

    string health_temp_temp;
    getline(cin, health_temp_temp);

    vector<string> health_temp = split_string(health_temp_temp);

    vector<int> health(n);

    for (int i = 0; i < n; i++) {
        int health_item = stoi(health_temp[i]);

        health[i] = health_item;
    }

    /*for(int i = 0; i < n; i++){
        std::pair<std::map<string,vector<int>>::iterator,bool> ret;

        ret = genes_val.insert ( std::pair<string,vector<int>>(genes[i],{health[i]}) );
          if (ret.second==false) {
            (genes_val[genes[i]]).push_back(health[i]);
          }
    }*/

    Aho ahoAlg;// = new Aho();
    //int val = 2;
   // ahoAlg.Init();
    for (int i = 0; i < genes.size(); i++)
    {
        ahoAlg.AddString(genes[i], i, health[i]); // Add all patterns to the structure
    }

    // Prepare algorithm for work (calculates all links in the structure):
    ahoAlg.PrepareAho();

    unsigned long long minhlthval = ULONG_MAX, maxhlthval = 0;

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        string firstLastd_temp;
        getline(cin, firstLastd_temp);

        vector<string> firstLastd = split_string(firstLastd_temp);

        int first = stoi(firstLastd[0]);

        int last = stoi(firstLastd[1]);

        string d = firstLastd[2];

        unsigned long long temp_val = 0;

        // Process the text. Output might be different; in my case, it's a count of
        // matches. We could instead return a structure with more detailed information.
        temp_val = ahoAlg.ProcessString(d, first, last);

        //cout<< countOfMatches <<"f"<<endl;


        if(temp_val > maxhlthval){
            maxhlthval = temp_val;
        }

        if( minhlthval> temp_val){
            minhlthval = temp_val;
        }
    }



    cout<< minhlthval << " " << maxhlthval;
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
