#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'stockmax' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY prices as parameter.
 */
 long maxProfit = 0;
 void getProfit(int day, int profit, int items, vector<int> prices){
    if(day == prices.size()){

        maxProfit = maxProfit<profit?profit:maxProfit;
        return;
    }
     //sell
     if(items > 0){
            int tmpprofit = profit + items*prices[day];
            int tmpitems = 0;
            (getProfit(day+1, tmpprofit, tmpitems, prices));
             maxProfit = maxProfit<tmpprofit ? tmpprofit : maxProfit;
     }


     getProfit(day+1, profit-prices[day], items+1, prices);
     maxProfit = maxProfit<(profit-prices[day])?(profit-prices[day]):maxProfit;
     getProfit(day+1, profit, items, prices);
     maxProfit = maxProfit<profit?profit:maxProfit;

 }

long stockmax(vector<int> prices) {

   long profit = 0;
        int maxSoFar = 0;
        for (int i = prices.size() - 1; i > -1 ; i--) {
            if (prices[i] >= maxSoFar) {
                maxSoFar = prices[i];
            }
            profit += maxSoFar - prices[i];
            cout<<profit<<endl;
        }
        return profit;
}

int main(){

    vector<int> pr = {1, 2, 100};
    cout<< stockmax(pr);
    return 0;
}
