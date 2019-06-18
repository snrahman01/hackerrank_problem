#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {

    int a[26] ={0};
    int val =0;

    for(int i = 0; i < s.size(); i++){
        a[s[i]-'a']++;
    }

    set<char> st(s.begin(), s.end());
    bool valid = true;
    long dis = 0;

    for(set<char>::iterator it = (st.begin()); it != st.end(); ++it){
        val = a[*next(st.begin())-'a'];

        if(abs(a[*it-'a']-val)==1 || a[*it-'a'] == 1){
            dis++;
            if(dis>1)
            {
                valid = false;
                break;
            }
        }
        else if(abs(a[*it-'a']-val)>1) {
            valid = false;
            break;
        }
    }

    if(valid){
        return "YES";
    }
    return "NO";

}

int main()
{
    string s = "abcdefghhgfedecba";
    cout<<isValid(s);
    return 0;
}
