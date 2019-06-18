
#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int anagram(string s) {


    if(s.size()%2 != 0)
        return -1;

    //1/2 sub string
    std::string s1 = s.substr(0, s.length()/2);
    std::string s2 = s.substr(s.length()/2);


    int arrS1[26] = {0};
    int arrS2[26] = {0};
    int charCount = 0;

    //count number of a character
    for(int i =0; i < s1.size(); i++){
            arrS1[s1[i]-'a']++;
            arrS2[s2[i]-'a']++;
    }

    for(int i =0; i < 26; i++){
        if(arrS1[i] != 0 && arrS1[i]>arrS2[i])
            charCount += arrS1[i]-arrS2[i];
    }

    return charCount;
}

int main()
{
    string s1 = "xaxbbbxx";
    string s2 = "abc";

    cout<< anagram( s1);
}


