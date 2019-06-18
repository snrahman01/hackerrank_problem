
#include<bits/stdc++.h>

using namespace std;

string funnyString(string s) {
    int l = s.size()-1;
    for(int i = 0; i < s.size()-1; i++){
        if(abs(s[i] - s[i+1]) != abs(s[l]-s[l-1])){

            return "Not Funny";
        }
        l--;
    }

    return "Funny";
}

int main()
{
    string a = "bcxz";

   cout<< funnyString(a);
}

