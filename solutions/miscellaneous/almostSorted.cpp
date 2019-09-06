#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    int startIndex = -1;
    int endIndex = -1;
    int up = 0, down = 0;
    bool brk = false;
    bool revers = false, swp = false;
    vector<int> narr = arr;
    int difC= 0;
    sort(narr.begin(), narr.end());
    for(int i = 0; i < arr.size(); i++){

        if(!brk && narr[i] != arr[i]){
                brk = true;
                difC++;
            startIndex = i;
        }
        else if(brk&& narr[i] != arr[i]){
                difC++;
            endIndex = i;
        }
    }
    if(startIndex==-1&&endIndex==-1){
        cout<<"yes";

    }
    else{

            int tmpVal;
            if(difC == 2){
                tmpVal = arr[startIndex];
            arr[startIndex] = arr[endIndex];
            arr[endIndex] = tmpVal;
                    if(is_sorted(arr.begin(), arr.end())){
                cout<<"yes"<<endl;
                cout<<"swap "<<startIndex+1<<" "<<endIndex+1;}
            }else{
                reverse(arr.begin()+startIndex, arr.begin()+endIndex+1);

                if(is_sorted(arr.begin(), arr.end())){
                    cout<<"yes"<<endl;
                    cout<<"reverse "<<startIndex+1<<" "<<endIndex+1;
                }else{
                cout<<"no";
                }
            }
    }
}

int main()
{
    vector<int> v = {1, 5, 4, 3, 2, 6};
    almostSorted(v);
    return 0;
}
