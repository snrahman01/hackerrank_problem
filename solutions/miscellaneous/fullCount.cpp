#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

bool sortcol( const vector<string>& v1,
               const vector<string>& v2 ) {
 return v1[0] > v2[0];
}

// Complete the countSort function below.
void countSort(vector<vector<string>> vect) {

map<long, string> m;

    for(int i = 0; i < vect.size()/2; i++){
        vect[i][1] = "-";
        if(m.find(stoul (vect[i][0],nullptr,0)) == m.end()){
            pair<long, string> p(stoul (vect[i][0],nullptr,0), vect[i][1]+" ");
            m.insert(p);
        }else{
            m[stoul (vect[i][0],nullptr,0)] += vect[i][1]+" ";
        }
    }

    for (int i=vect.size()/2; i<vect.size(); i++)
    {
        if(m.find(stoul (vect[i][0],nullptr,0)) == m.end()){
            pair<long, string> p(stoul (vect[i][0],nullptr,0), vect[i][1]+" ");
            m.insert(p);
        }else{
            m[stoul (vect[i][0],nullptr,0)] += vect[i][1]+" ";
        }
    }

    for ( map<long, string>::iterator itr = m.begin(); itr != m.end(); ++itr) {
        cout <<itr->second;
    }
}
int main()
{
    vector< vector<string> > vect{{"1", "aaa"},
                                {"2", "b"},
                                {"0","c"}};
                                countSort(vect);

}
