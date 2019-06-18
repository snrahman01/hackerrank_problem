#include <iostream>
#include <regex>
#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {

    int arrFric[26] = {0};
    bool b = true;
    int gemCount = 0;
    for(int i = 0; i < arr.size(); i++){
        set<char> val (arr[i].begin(), arr[i].end());

        for (auto it=val.begin(); it != val.end(); ++it) {
            int t = *it -'a';
            arrFric[t]++;
            if(i == (arr.size()-1) && arrFric[t] == arr.size())
            {
                gemCount++;
            }
        }
    }
    return gemCount;

}

int main()
{
    string a = "hhaacckkekraraannk";
    vector<string> v = {"abcdde",
    "baccd",
    "eeabg"};
    cout<< gemstones( v);
}

