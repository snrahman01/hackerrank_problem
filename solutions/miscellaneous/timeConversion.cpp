#include <bits/stdc++.h>

using namespace std;


vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

string timeConversion(string s) {
    /*
     * Write your code here.
     */


     if (s.find("AM") != std::string::npos) {
        vector<string> result;
        s.erase(8, 2);
        result = split(s, ':');
        int i = stoi(result[0]);
        if(i == 12){
            result[0] = "00";
        }
        return result[0]+":"+result[1]+":"+result[2];
     }
     else if (s.find("PM") != std::string::npos) {
       vector<string> result;
        s.erase(8, 2);
        result = split(s, ':');
         int i = stoi(result[0]);
         if(i != 12)
            i+=12;

            result[0] = to_string(i);

        return result[0]+":"+result[1]+":"+result[2];
     }
    return "";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
