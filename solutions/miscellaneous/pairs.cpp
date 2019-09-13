#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the pairs function below.
int pairs(int k, vector<int> arr) {

    int i=0, c=0;
    int n = arr.size();
    sort(arr.begin(), arr.end());

    while(i < n) {

        vector<int>::iterator it = find(arr.begin()+i+1, arr.end(), arr[i]+k);
        if(it != arr.end())
            c++;
        i++;
    }
    return c;
}

int main()
{
    vector<int> v = {1, 5, 3, 4, 2};
    int k = 2;
    cout<<pairs(2, v);
    return 0;
}
