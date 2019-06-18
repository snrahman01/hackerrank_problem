
#include<bits/stdc++.h>

using namespace std;

int beautifulBinaryString(string b) {

    regex r("010");
    string s2 = regex_replace(b, r, "");
    return (b.size()-s2.size())/3;
}

int main()
{
    string a = "0100101010";

   cout<< beautifulBinaryString(a);
   return 0;
}

