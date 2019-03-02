#include "Aho.h"

class Aho;
Aho::Aho()
{
    //ctor
    size = 0;
    root = 0;
    Init();

}

Aho::~Aho()
{
}

void Aho::Init()
{
    Vertex v;
    Trie.push_back(v);
    size++;
}

void Aho::AddString(string s, int wordID)
{
	int curVertex = root;

	for (int i = 0; i < s.size(); ++i) // Iterating over the string's characters
	{
		char c = s[i];

		// Checking if a vertex with this edge exists in the trie:
		//Trie[curVertex].Children['c'] = 1;
		if (Trie[curVertex].Children.count(c) == 0)
		{

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
	Trie[curVertex].WordID = wordID;
	WordsLength.push_back(s.size());
}

void Aho::PrepareAho()
{
	queue<int> vertexQueue;// = new queue<int>();
	vertexQueue.push(root);
	while (vertexQueue.size() > 0)
	{
		int curVertex = vertexQueue.front();
		vertexQueue.pop();
		CalcSuffLink(curVertex);

		for (std::map<char,int>::iterator it= Trie[curVertex].Children.begin(); it!= Trie[curVertex].Children.end(); ++it)
        {
			vertexQueue.push(it->second);
		}
	}
}

void Aho::CalcSuffLink(int vertex)
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

int Aho::ProcessString(string text)
{
	// Current state value
	int currentState = root;
	int result = 0;

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

            result++;
			int indexOfMatch = j + 1 - WordsLength[Trie[checkState].WordID];

			// Trying to find all matched patterns of smaller length
			checkState = Trie[checkState].SuffixLink;
		}
	}

	return result;
}
