
#include <bits/stdc++.h>
using namespace std;
string superReducedString(string s) {
    string s1 = s;
    for(int i = 1; i < s.size();i++){
        if(s[i] == s[i-1]){
            s.erase(i-1, 2);
            i = 0;
        }
    }

    if(s.size()==0){
        s = "Empty String";
    }

    return s;
}

int main()
{
    string s = "aaabccddd";
    cout << superReducedString(s);
    return 0;
}
