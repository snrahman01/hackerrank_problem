#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the larrysArray function below.
string larrysArray(vector<int> A) {

    int inv = 0;
    int n = A.size();
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (A[i] > A[j])
                inv ++;
    if (inv%2==0)
        printf("YES\n");
    else
        printf("NO\n");

}

int main()
{
    vector<int> v = {1, 2, 3, 5, 4};
    cout<<larrysArray(v);
    return 0;
}
