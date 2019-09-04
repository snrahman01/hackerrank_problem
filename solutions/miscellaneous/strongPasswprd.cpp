#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong

    regex lower(".*[a-z]+.*"); // Geeks followed by any character

    regex upper(".*[A-Z]+.*");

    regex digits(".*[0-9]+.*");
    regex special(".*[-!@#\\$%\\^\\&\\*\\(\\)\\+]+.*");

    int numLet = 0;
    // regex_match function matches string a against regex b
    if ( !regex_match(password, lower) )
    {    numLet++;}

    if ( !regex_match(password, upper) )
     {   numLet++;}

    if ( !regex_match(password, digits) )
        {numLet++;}

    if ( !regex_match(password, special) )
     {   numLet++;}

    if(n<6){
        int a = 6-n;
        if(numLet>a)
           { return numLet;}
        else
        {
            return (numLet+(a-numLet));

        }
    }
    else
        {return numLet;}

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
