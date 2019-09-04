// C++ program to rotate a matrix

#include <bits/stdc++.h>

//#define R 4
//#define C 4
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(int mm, int nn, vector<vector<int>> mat, int r) {



    /*
    row - Staring row index
    m - ending row index
    col - starting column index
    n - ending column index
    i - iterator
    */



    int row = 0, col = 0;
    int prev, curr;

    int m = mm; //mat.size();
    int n = nn;//mat[0].size();
        while (row < m && col < n)
        {

            if (row + 1 == m || col + 1 == n)
                break;

            int noElmnt = (m-row)+(n-col-1);
            if(m-row-1 >= 0 && n-col-2 >=0){
                noElmnt += m-row-1+n-col-2;
            }

          int tempRot = r%noElmnt;
            // Store the first element of next row, this
            // element will replace first element of current
            // row

            //cout<<endl;
            //cout<< "noOfEL= " << noElmnt<<endl;
        for(int k = 0; k<tempRot; k++){
            prev = mat[row][col];

            /* Move elements of first column from the remaining rows */
            for (int i = row+1; i < m; i++)
            {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
            //col++;

            /* Move elements of last row from the remaining columns */
            for (int i = col+1; i < n; i++)
            {
                curr = mat[m-1][i];
                mat[m-1][i] = prev;
                prev = curr;
            }
            //m--;

            /* Move elements of last row from the remaining rows */
            if (col < n)
            {
                for (int i = m-2; i >= row; i--)
                {
                    curr = mat[i][n-1];
                    mat[i][n-1] = prev;
                    prev = curr;
                }
            }
            //n--;

            /* Move elements of first column from the remaining rows */
            if (row < m-1)
            {
                for (int i = n-2; i >= col; i--)
                {
                    curr = mat[row][i];
                    mat[row][i] = prev;
                    prev = curr;
                }
            }
        }
        row++;
        col++;
        m--;
        n--;
    }

    // Print rotated matrix
    for (int i=0; i<mat.size(); i++)
    {
        for (int j=0; j<mat[0].size(); j++)
        cout << mat[i][j] << " ";
        cout << endl;
    }

}


/*int main()
{
    // Test Case 1
        vector<vector<int>> matrix = { {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16} };

    // Tese Case 2
    /* int a[R][C] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                    };
    */ //matrixRotation(R, C, matrix, 16);
    //return 0;
//}*/

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(m, n, matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}



