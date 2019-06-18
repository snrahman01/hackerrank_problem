#include <bits/stdc++.h>

using namespace std;

// Complete the separateNumbers function below.
void separateNumbers(string s) {

    long number = -1;
    int i = 1;

    for(; i <= s.size()/2; i++){
        string s1 = s.substr(0, i);
        long a = stol(s1, nullptr, 10);
        number = a;
        string s2 = to_string(a);

        while(s2.size()< s.size()){
            s2 += to_string(++a);
        }

        if(s2 == s){
                break;
        }
    }
    if(i > s.size()/2){

        cout << "NO"<<endl;
    }
    else
    {

        cout << "YES"<< " "<<number<<endl;
    }
}

int main()
{
    separateNumbers("99100");
    return 0;
}
