

#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {

    vector<string> v;
    vector<bool> values(10000000);
    int cnum = 1;

    for(int i = 1; i < s.size(); i++){
            int weight = (s[i-1]-'a'+1)*cnum;
            values[weight] = true;
            if(s[i] == s[i-1]){
               cnum++;
            }
            else{
                cnum = 1;
            }
    }

    values[((s[s.size()-1]-'a'+1)*cnum)] = true;

    for(int i =0; i < queries.size(); i++){
            if(values[queries[i]]){
                v.push_back("Yes");
            }else{
            v.push_back("No");
        }
    }

    return v;
}
int main(){
    vector<int> v = {1,3,12,5,9,10};
    string ss = "abccddde";
    vector<string> s = weightedUniformStrings(ss, v);
    for(int i =0; i < s.size(); i++){
        cout<<s[i]<< " ";
    }
    return 0;
}
