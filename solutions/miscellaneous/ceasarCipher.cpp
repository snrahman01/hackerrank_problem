#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int rot) {

    char a;
    cin >> rot;
    cin >> s;
    cin >> rot;
    for(auto &c: s){
        if(isalpha(c)){
            a = isupper(c)?'A':'a';
            c= a + (c - a + rot)%26;
        }
    }
 return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
