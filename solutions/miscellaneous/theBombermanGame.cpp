#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
vector<string> makeAllLast(vector<string> grid){

    vector<string> newGrid;
    for(int i = 0; i < grid.size(); i++){

            string s = grid[i];

            for(int j = 0; j< s.size(); j++){
               if( s[j] == 'O'){
                    s[j] = '3';
               }
               else
               {
                   s[j] = 'O';
               }
            }
            newGrid.push_back(s);
        }
 return newGrid;
}

vector<string> getFinalString(vector<string> newGrid){

        for(int i = 0; i < newGrid.size(); i++){
            for(int j = 0; j< newGrid[i].size(); j++){
               if(newGrid[i][j] == '3'){
                    newGrid[i][j]='.';
                    if(i > 0){
                        newGrid[i-1][j] = '.';
                    }
                    if(j > 0){
                        newGrid[i][j-1] = '.';
                    }

                    if(i < newGrid.size()-1 && newGrid[i+1][j] != '3' ){
                        newGrid[i+1][j] = '.';
                    }
                    if( j < newGrid[i].size()-1 && newGrid[i][j+1] != '3'){
                        newGrid[i][j+1] = '.';
                    }

               }
            }
        }
        return newGrid;
}

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {

    int val = n%4;
    vector<string> newGrid;


    cout<<val;
    if(n == 1){
        return grid;
    }
    else if(val == 3){
            newGrid = makeAllLast(grid);
        newGrid = getFinalString(newGrid);

    }
    else if(val == 1){
            newGrid = makeAllLast(grid);
        newGrid = getFinalString(makeAllLast(getFinalString(newGrid)));
    }
    else if(val == 2 || val == 0){

        string s="";
        for(int i = 0; i < grid[0].size(); i++){
            s += "O";
        }
        for(int i = 0; i < grid.size(); i++){
            newGrid.push_back(s);
        }
    }
 return newGrid;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
