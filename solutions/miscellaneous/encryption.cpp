#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {

    //s.erase( remove( s.begin(), s.end(), ' ' ), s.end() );
    int len = s.size();

   // cout<< s;
    int row = floor(sqrt(len));
    int col = ceil(sqrt(len));

    if(col*row<len){
            if(row<col)
                row++;
    }
    vector<char> ns;
    for(int i = 0; i < col; i++){

        for(int j = 0; j < row; j++){
                if((i+(col*j))<len)
                    ns.push_back(s[i+(col*j)]);
        }
        ns.push_back(' ');
    }
    string str(ns.begin(), ns.end());
 return str;
}

int main()
{
    string s = "feedthedog";

    cout<< encryption(s);
    return 0;
}
