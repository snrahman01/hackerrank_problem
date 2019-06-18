#include <bits/stdc++.h>

using namespace std;

int hackerrank(int n, string password){
    regex lower(".*h+.*a+.*c+.*k+.*e+.*r+.*r+.*a+.*n+.*k+.*");
    int numLet = 0;

    if ( regex_match(password, lower) )
    { numLet++;}

    return numLet;
}
int main()
{
   string a = "hhaacckkekraraannk";
   cout<< hackerrank(3,a );
}
