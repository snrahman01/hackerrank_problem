#include <bits/stdc++.h>

using namespace std;

string abbreviation(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1));// = {false};

    dp[0][0] = true;

    for(int i = 0; i< n; i++){
        for(int j = 0; j <= m; j++){
            if(!dp[i][j]) {continue;}
            if(j<m && toupper(a[i]) == b[j]){dp[i+1][j+1] = true;}
            if(islower(a[i]))   dp[i+1][j] = true;
        }
    }

    return (dp[n][m] ? "YES" : "NO");
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
