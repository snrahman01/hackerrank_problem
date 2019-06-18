#include <bits/stdc++.h>
#include <algorithm>
#include<iostream>
using namespace std;
// Complete the alternate function below.
int alternate(string s) {

    set<char> a(s.begin(), s.end());
    int len = 0;
 for(std::set<char>::iterator it = a.begin(); it != a.end(); ++it){
    string newString = s;

    for(std::set<char>::iterator it1 = next(it, 1); it1 != a.end(); ++it1){
        string s1 = "[^";
        s1 += *it;
        s1 += " ";
        s1 += *it1;
        s1 += "]";

        regex r(s1);
        newString = regex_replace(s, r, "");

        if(len < newString.size()){
            bool check = false;
            for(int i = 0; i < newString.size()-1; i++)
            {
                if(newString[i] == newString[i+1]){
                    check = true;
                    break;
                }
            }
            if(!check){
                len = newString.size();
            }
        }
    }
 }
 return len;

}

int main()
{
    string s = "abaacdabd";
    cout<< alternate(s);
    return 0;
}
