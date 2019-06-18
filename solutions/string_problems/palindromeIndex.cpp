#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {

    int i = 0, j = s.size()-1;
    int index = -1;
    bool isPossible = false;
    while(i <= j){

        if(s[i] != s[j]){
            if(s[i] == s[j-1]){
                index = j;
                isPossible = true;
            }
            if(s[i+1] == s[j]){
                index = i;
                isPossible = true;
            }

            if(isPossible){

                string test = s;
                test.erase(test.begin()+index);
                string s1 = test;
                reverse(s1.begin(), s1.end());

                if(test != s1){
                    index = -1;
                }
                else{
                    break;
                }
            }


            break;
        }
        i++;
        j--;
    }

    if(index != -1){
        s.erase(s.begin()+index);
        string s1 = s;
        reverse(s1.begin(), s1.end());

        if(s != s1){
            index = -1;
        }
    }
    return index;

}

int main()
{
    string s = "hgygsvlfwcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcflvsgygh";

    cout<< palindromeIndex(s);
    return 0;
}
