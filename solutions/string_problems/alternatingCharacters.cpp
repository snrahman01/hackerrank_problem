
#include<bits/stdc++.h>

using namespace std;

int alternatingCharacters(string s) {

    //One or more A and B
    regex r("A+");
    regex r1("B+");

    //Replace more than 1 A and B
    string s2 = regex_replace(s, r, "A");
    string s3 = regex_replace(s2, r1, "B");

    return (s.size()-s3.size());
}

int main()
{
    string a = "AAABBB";

   cout<< alternatingCharacters(a);
   return 0;
}


