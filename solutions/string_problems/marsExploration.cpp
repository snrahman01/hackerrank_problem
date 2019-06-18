#include<bits/stdc++.h>

using namespace std;

int marsExploration(string s) {

    int countn = 0;

    for(int i = 0; i < (s.size()); i+=3){

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
    string a = "SOSSWEWSSTTS";

   cout<< marsExploration(a);
}

