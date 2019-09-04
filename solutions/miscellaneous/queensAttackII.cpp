#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    vector<int> dis = {min(abs(r_q - n), abs(c_q - 1)), min(abs(r_q - n), abs(c_q - n)),
    min(abs(r_q - 1), abs(c_q - 1)), min(abs(r_q - 1), abs(c_q - n)),
    (c_q - 1), (n - c_q), (r_q -1), (n - r_q)};
    int topLeft = 0;
    int topRight = 1;
    int dwnLeft = 2;
    int dwnRight = 3;
    int left = 4;
    int right = 5;
    int dwn = 6;
    int top = 7;
    for(int i = 0; i < obstacles.size(); i++){
        int r_d = obstacles[i][0] - r_q;
        int c_d = obstacles[i][1] - c_q;

        int valmin = min(abs(r_d), abs(c_d))-1;
        //cout<<"rd= "<< abs(r_d)<<", cd = "<< abs(c_d) <<", "<<valmin<< ", ";
        if(abs(r_d) == abs(c_d)){
            if(r_d>0 && c_d<0 && (dis[topLeft]>valmin)){
                    dis[topLeft] = valmin;
            }
            else if(r_d>0 && c_d>0 && (dis[topRight]>valmin)){
                    dis[topRight] = valmin;
            }
            else if(r_d<0 && c_d<0 && (dis[dwnLeft]>valmin)){
                    dis[dwnLeft] = valmin;
            }
            else if(r_d<0 && c_d>0 && (dis[dwnRight]>valmin)){
                    dis[dwnRight] = valmin;
            }
        }
        else if(r_d == 0){
            if(c_d < 0 && dis[left]>abs(c_d)){
                dis[left] = abs(c_d)-1;
            }
            else if(c_d > 0 && dis[right]>abs(c_d)){
                dis[right] = abs(c_d)-1;
            }
        }
        else if(c_d == 0){
            if(r_d < 0 && dis[dwn]>abs(r_d)){
                dis[dwn] = abs(r_d)-1;
            }
            else if(r_d > 0 && dis[top]>abs(r_d)){
                dis[top] = abs(r_d)-1;
            }
        }

    }

    int totalDis = 0;

    for(int i = 0; i < dis.size(); i++){
          //  cout << dis[i] << " ";
        totalDis += dis[i];
    }


    //cout<<endl;
    return totalDis;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

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
