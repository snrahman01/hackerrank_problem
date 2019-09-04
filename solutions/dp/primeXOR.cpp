#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
    long long dp[1001][8192] ={0};
vector<int> make_prime()
{
  bool prime[8192];
  vector<int> P;
  memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=8191; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=8191; i += p)
                prime[i] = false;
        }
    }
    for(int i=2;i<8192;i++)
    {
       if(prime[i]) P.push_back(i);
    }
    return P;
}


// Complete the primeXor function below.
int primeXor(vector<int> a) {
//cout<<"5";
    //cout<<"1";
    int freq[1001] = {0};
    dp[0][0] = 1;

   // cout<<"x";
    for(int i = 0; i < a.size(); i++){
            //cout<< a[i]<<endl;
        freq[a[i] - 3500]++;
    }

    //cout<<"f"<<endl;
    for(int i = 1;i < 1001; i++){
        for(int j = 0; j < 8192; j++){
            dp[i][j] = (dp[i-1][j]*(1+(freq[i-1]/2)) + dp[i-1][j^((i-1)+3500)]*((1+freq[i-1])/2))%1000000007;
        }
    }

    long long subCount = 0;

   // cout<<"h"<<endl;
    vector<int> P = make_prime();
    for(int i = 0; i < P.size(); i++){
        subCount =  (subCount+dp[1000][P[i]])%1000000007;
    }
    return subCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        int result = primeXor(a);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
