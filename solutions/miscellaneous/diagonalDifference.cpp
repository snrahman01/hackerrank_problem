#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> arr) {
int val1 = 0, val2 =0;
int si = arr.size() - 1;
for(int i =0; i <= si; i++){

val1 += arr[i][i];
val2 += arr[i][si - i];
}

return abs(val1-val2);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
