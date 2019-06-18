#include <bits/stdc++.h>

using namespace std;

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s) {

    int countAction = 0, j = (s.size() -1);
    for(int i =0; i < j; i++){
        countAction += abs(s[i] - s[j--]);
    }

    return countAction;
}

int main()
{
    string s = "abc";
    cout<< theLoveLetterMystery(s);
    return 0;
}
