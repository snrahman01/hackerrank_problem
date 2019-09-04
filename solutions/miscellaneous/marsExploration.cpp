#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {

int countn = 0;
    for(int i = 0; i < (s.size()); i+=3){

            cout<<s[i]<<endl;
        if(s[i]!='S')
        {
            countn++;
        }

        if(s[i+1]!='O'){ countn++;}
        if(s[i+2]!='S') {  countn++;}

    }

    return countn;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
