#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int makingAnagrams(string s1, string s2) {

    int arrS1[26] = {0};
    int arrS2[26] = {0};
    bool b = true;
    int charCount = 0;

    for(int i =0; i < s1.size(); i++){ arrS1[s1[i]-'a']++; }
    for(int i =0; i < s2.size(); i++){ arrS2[s2[i]-'a']++; }
    for(int i =0; i < 26; i++){ charCount += abs(arrS1[i]-arrS2[i]); }

    return charCount;

}

int main()
{
    string s1 = "cde";
    string s2 = "abc";

   cout<< makingAnagrams( s1, s2);
}


