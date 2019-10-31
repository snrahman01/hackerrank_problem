#include <bits/stdc++.h>

using namespace std;

// Complete the substrings function below.
int substrings(string n) {

long long sum = 0;

long long j = 1;
for(int i = n.size()-1; i >= 0; i--){
    int a = n[i] - '0';
    sum = (sum + a*j*(i+1))%1000000007;
    j = ((j*10)+1)%1000000007;
}
return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
