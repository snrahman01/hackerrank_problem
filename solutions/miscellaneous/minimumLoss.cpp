#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumLoss function below.
int minimumLoss(vector<long> price) {

    vector<pair<long,long>> vec;
    for(int x=0;x<price.size();x++){

            vec.push_back(pair<long,long>(x,price[x]));
    }

    sort(vec.begin(),vec.end(),[](pair<long,long>elem1,pair<long,long>elem2){return elem1.second < elem2.second;});

    long ind = -1;
    long cost = LONG_MAX;
    for(long i = 0; i < vec.size()-1; i++){
        pair<long, long> p1 = vec[i];
        pair<long, long> p2 = vec[i+1];

        if((p2.second - p1.second)<cost && (p1.first > p2.first)){
            cost = (p2.second - p1.second);
            }
    }
    return cost;
}

int main()
{
    vector<long> b = {20, 7, 8, 2, 5};
    cout<< minimumLoss(b);
    return 0;
}
