#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
ll power(ll x, ll y);

const int MAX = 100001;
const ll P = 1000000007;
ll fact[MAX];
ll mMulInv[MAX];
int cnt[MAX][26];

void initialize(string s) {

    fact[0] = 1;
    mMulInv[0] = 1;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j <26; j++) {
            cnt[i][j] = 0;
        }
    }

    for(int i = 1; i < MAX; i++){
        fact[i] = (fact[i-1]*i)%P;
        mMulInv[i] = power(fact[i], P-2)%P;
    }

    for (int i = 0; i < s.size(); i++) {
        cnt[i + 1][s[i] - 'a']++;
    }
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            cnt[i][j] += cnt[i - 1][j];
        }
    }
}

ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	long long  p = power(x, y/2);
	p = (p * p) % P;

	return (y%2 == 0)? p : (x * p) % P;
}
ll answerQuery(int l, int r) {

    int cntEven = 0;
    int cntOdd = 0;
    long long num1 = 1;

    for(int i = 0; i < 26; i++){
            int alpCnt = cnt[r][i] - cnt[l-1][i];
        if( alpCnt != 0){
            cntEven += (alpCnt)/2;
            num1 *= mMulInv[alpCnt/2];
            cntOdd += alpCnt%2;
        }
    }
    cntOdd = cntOdd == 0? 1: cntOdd;
    ll res = (num1*cntOdd)%P;
    res = (res*fact[cntEven])%P;
    return res;
}

int main()
{
     ifstream fin;
    fin.open("F:\\tst.txt");
    ofstream fout;
    fout.open("F:\\out.txt");

    string s;
    getline(fin, s);

    initialize(s);

    string q_temp;
    getline(fin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(fin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int l = stoi(first_multiple_input[0]);

        int r = stoi(first_multiple_input[1]);

        long long result = answerQuery(l, r);

        if(result == 490299117)
            cout << l<< " "<< r << " "<< result << "\n";
            else
                fout<<result<<"\n";
    }

    fout.close();

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
