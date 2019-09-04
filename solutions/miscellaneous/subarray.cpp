#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {

    int n = arr.size();
    int maxSubArray = INT_MIN;
    int maxSubSeq = 0;
    int maxNeg = INT_MIN;
    int mx = 0;
    vector<int> res;
    for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                maxSubSeq += arr[i];
            }else if(maxNeg < arr[i]){
                maxNeg = arr[i];
            }
            mx = max((mx+arr[i]), arr[i]);
            maxSubArray = max(maxSubArray, mx);
    }

    res.push_back(maxSubArray);

    if(maxSubSeq>0){
        res.push_back(maxSubSeq);
    } else{
        res.push_back(maxNeg);
    }


    return res;

}

int main()
{
    //ofstream fout;
    //fout.open("F:\\out01.txt");
    ifstream fin;
    fin.open("F:\\tst.txt");
    int t;
    fin >> t;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<< t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        fin >> n;

        fin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<n;
        string arr_temp_temp;
        getline(fin, arr_temp_temp);


        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

              //  cout<< arr_item << ", ";
            arr[i] = arr_item;

        //fin.ignore(numeric_limits<streamsize>::max(), '\n');
       // cout<< arr[i];
        }

        cout<< endl;
        cout<< endl;
        cout<<"============================================="<<arr.size()<<"=========="<<endl;
        vector<int> result = maxSubarray(arr);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
               cout << " ";
            }
        }

       cout << "\n";
    }
cout<<"rrr";
  //  fout.close();
fin.close();
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

