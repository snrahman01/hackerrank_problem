#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

    map<string, int> ana;

    for (int i = 0; i < s.size(); i++)
        for (int len = 1; len <= s.size() - i; len++) {
                string a1 = s.substr(i, len);
                sort(a1.begin(), a1.end());
                if ( ana.find(a1) == ana.end() ) {
                    ana.insert(pair<string, int>(a1, 1));
                } else {
                   ana[a1]++;
                }
        }

    int val = 0;
    for (std::map<string,int>::iterator it=ana.begin(); it!=ana.end(); ++it){


        if(it->second != 1){
            val += ((it->second)*(it->second-1))/2;
        }

    }
    return val;
}

int main()
{

   // cout<<nCr(29,2);
    string s = "abba";
    cout<<"val="<<sherlockAndAnagrams(s);
    return 0;
}
