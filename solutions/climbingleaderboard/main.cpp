#include <bits/stdc++.h>
#include<map>

using namespace std;

vector<string> split_string(string);

// Complete the clim bingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

    map<int, int> pos;
    int ran = 1;
    int alcCount = 0;
    vector<int> position(alice.size());
    for(int in = 0; in < scores.size(); in++){
        std::pair<std::map<int,int>::iterator,bool> ret;

        ret = pos.insert ( std::pair<int,int>(scores[in],ran++) );
        if (ret.second==false) {
                ran--;
        }
    }

    int i = scores.size();

    while(alice.size()> alcCount){

        if(alice[alcCount]>scores[i] && i == 0){
            position[alcCount]=(pos[scores[i]]);
            alcCount++;
            continue;
        }
        if(alice[alcCount]>scores[i]){
            i--;
        }
        if(alice[alcCount]== scores[i])
        {
            position[alcCount]=(pos[scores[i]]);
            alcCount++;
        }
        else if(alice[alcCount]<scores[i]){
            position[alcCount]= (pos[scores[i]]+1);
            alcCount++;
        }
    }

    return position;
}

int main()
{
    int scores_count = 7;

    string scores_temp_temp;
    vector<int> scores(scores_count);

     int scr [] = { 100, 100, 50, 40, 40, 20, 10 };
    for (int i = 0; i < scores_count; i++) {
        scores[i] = scr[i];//scores_item;
    }

    int alice_count = 4;

    string alice_temp_temp;

   int alc[] ={5, 25, 50, 120};
    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        alice[i] = alc[i];
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";
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
