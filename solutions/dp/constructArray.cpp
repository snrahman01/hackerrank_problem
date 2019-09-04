#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countArray function below.
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.


    long long a = 0, b = 1;
    for(int i = 1; i < n; i++){

        long long atemp = a, btemp = b;
        b = ((k-1)*atemp)%1000000007;
        a = ((k-2)*atemp + btemp)%1000000007;

    }

    return (x == 1)?b:a;

}

int main()
{
     cout<< countArray(4,3,2);
    return 0;
}
