#include <bits/stdc++.h>

using namespace std;

string timeInWords(int h, int m) {
    string hr[31] = {"o\' clock",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "quarter",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine",
        "half"};

        string s = "";
    if(m > 30){
        s +=  (60-m) != 15 ? (hr[60 - m]+" minutes to "+ hr[h+1]) : (hr[60 - m]+" to "+ hr[h+1]);
    }else {
        if(m == 0)
            s += hr[h] + " " + hr[m];
        else if (m == 1)
            s += hr[m]+" minute past "+ hr[h];
        else s +=  (m != 15) && (m != 30)? (hr[m]+" minutes past "+ hr[h]) : (hr[m]+" past "+ hr[h]);
    }

    return s;
}

int main(){
    cout<< timeInWords(1, 1);
}
