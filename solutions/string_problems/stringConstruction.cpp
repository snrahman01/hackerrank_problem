#include <bits/stdc++.h>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {
    set<char> uniqueChar(s.begin(), s.end());
    return uniqueChar.size();
}

int main()
{
    string s = "abcd";
    cout << stringConstruction(s);
    return 0;
}
