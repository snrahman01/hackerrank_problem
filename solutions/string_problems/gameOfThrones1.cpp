#include <bits/stdc++.h>

using namespace std;

// Complete the stringConstruction function below.
string gameOfThrones(string s) {
    int friq[26] = {0};

    for(int i =0; i < s.size(); i++){
        friq[s[i]-'a']++;
    }

    int countOdd = 0;
    for(int i =0; i < 26; i++){
        if(friq[i]%2 != 0){
            countOdd++;
            if(countOdd > 1){
                return "NO";
            }
        }
    }

    return "YES";
}

int main()
{
    string s = "cdefghmnopqrstuvw";
    cout << gameOfThrones(s);
    return 0;
}

