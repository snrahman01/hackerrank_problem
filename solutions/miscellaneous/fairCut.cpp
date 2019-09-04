#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the fairCut function below.
 */
int fairCut(int k, vector<int> arr) {
    /*
     * Wriate your code here.
     */

     int n = arr.size();

     sort(arr.begin(), arr.end());
     cout<<
     vector<vector<vector<int>>> dp;
     int alpha=0, beta=0, gama=0;
     dp[0][0][0]  = 0;

     while(alpha < n && beta < k){
        cout<<" -"<<endl;
        int sum1 = dp[alpha+1][beta][gama] = dp[alpha][beta][gama]+beta*arr[alpha+1] - gama;

        //dp[alpha+1][beta+1][gamma+A[alpha+1]] = dp[alpha][beta][gamma] + (alpha-beta)*A[alpha+1] - (summation of A from 0 to i - gamma)

        int sum2 = dp[alpha+1][beta+1][gama+arr[alpha+1]] = dp[alpha][beta][gama] + (alpha - beta)*arr[alpha+1] - (accumulate(arr.begin(), arr.begin()+alpha+1, 0) - gama);

        alpha++;
        gama = sum1>sum2 ? gama + arr[alpha+1] : gama;
        beta = sum1> sum2 ? beta+1 : beta;
        cout<<sum1<<" "<<sum2<<endl;

     }

     cout<< dp[alpha][beta][gama]<<endl;
}

int main()
{
    vector<int> arr = {4, 3, 1, 2};
    int k = 2;

    fairCut(2, arr);
    return 0;
}
