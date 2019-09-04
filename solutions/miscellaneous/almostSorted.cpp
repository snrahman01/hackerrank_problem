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
            //cout<<startIndex<<":"<<arr[startIndex]<<" "<<endIndex<<":"<<arr[endIndex]<<endl;

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
   /* vector<int> v = {4104, 8529, 49984, 54956, 63034, 82534, 84473, 86411, 92941, 95929, 108831, 894947, 125082, 137123, 137276, 142534, 149840, 154703, 174744, 180537, 207563,
     221088, 223069, 231982, 249517, 252211, 255192, 260283, 261543, 262406, 270616, 274600, 274709, 283838, 289532, 295589, 310856, 314991, 322201 ,339198, 343271, 383392,
      385869, 389367, 403468, 441925, 444543, 454300, 455366, 469896, 478627, 479055, 484516, 499114, 512738, 543943, 552836, 560153, 578730, 579688, 591631, 594436, 606033,
      613146, 621500, 627475, 631582, 643754, 658309, 666435, 667186, 671190, 674741, 685292, 702340, 705383, 722375, 722776, 726812, 748441, 790023, 795574, 797416, 813164,
      813248, 827778, 839998, 843708, 851728, 857147, 860454, 861956, 864994, 868755, 116375, 911042, 912634, 914500, 920825, 979477};*/
    //vector<int> v = {4, 2};
    almostSorted(v);
    return 0;
}
