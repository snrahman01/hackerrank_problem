#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;

    cin>>n;
    cin>>q;

    vector<vector<int>> a(n);

    for(auto &i: a){
        int col;
        cin>>col;
        i = vector<int>(col);
        for(auto &j:i){
            cin>>j;
        }
    }
    for(int i = 0; i <q; i++){
        cin>>index1;
        cin>>index2;

        cout<<a[index1][index2]<<endl;
    }
    return 0;
}

