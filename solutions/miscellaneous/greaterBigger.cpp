#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w1) {

    string w = w1;
    int alph[26] = {0};
    string newS = "";
    int start = w[w.size()-1] - 'a';
    int prev = start;
    bool isSort = true;
    int minBig = -1;
    int minBigPos = -1;

    int checkItem = start;
    for(int i = w.size()-1; i >= 0; i--){
        int val = (w[i]-'a');
        if( checkItem > val){
            minBig = i;
            //cout<<w[i]<<" "<<i<<endl;
            break;
        } else {
            checkItem = val;
        }
        alph[val]++;
    }

   // cout<<w<<endl;
    if(minBig > -1){
    int minVal = w[minBig] - 'a';
    for(int i = w.size()-1; i>minBig; i--){
            int val = w[i] - 'a';
        if(val>minVal){
            char tmpC = w[minBig];
            w[minBig] = w[i];
            w[i] = tmpC;
            alph[minVal]++;
            alph[val]--;
            break;
        }
    }
 //cout<<w<<endl;
    w.erase(minBig+1, w.size()-minBig);
    //cout<<w<<endl;
   for(int i = 0; i < 26; i++){
        if(alph[i]>0){
                for(int j = 0; j< alph[i]; j++)
                    w += (char)(i+'a');
        }
    }
    }else{
        w = "no answer";
    }
    return w1;
}

int main()
{
    ifstream fin;
    fin.open("F:\\tst.txt");
    ofstream fout;
    fout.open("F:\\out.txt");

    long T;
    fin >> T;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<T<<endl;
    long k = 0;
    for (long T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(fin, w);
        string result = biggerIsGreater(w);
        //fout<< w<<"\n";
        fout << result << "\n";
        k++;
    }

    cout<<k;
    fin.close();
    fout.close();

    return 0;
}
