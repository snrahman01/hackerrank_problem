#include <iostream>
#include <regex>
#include <ctype.h>
#include<bits/stdc++.h>

using namespace std;

string pangrams(string s) {

    regex re("[^a-z]");
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string s1 = (regex_replace((s), re, ""));
    set<char>ss (s1.begin(), s1.end());

    if (ss.size() == 26){
        return "pangram";
    }
    else
    {
        return "not pangram";
    }

}

int main()
{
    string a = "We promptly judged antique ivory buckles for the next prize";

   cout<< pangrams(a);
}
