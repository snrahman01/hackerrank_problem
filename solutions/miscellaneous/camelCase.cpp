#include <bits/stdc++.h>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {

size_t count_upper = count_if(s.begin(), s.end(),
               [](unsigned char ch) { return isupper(ch); });
        return (count_upper+1) ;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
