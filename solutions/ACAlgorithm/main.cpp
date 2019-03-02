#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include<Aho.h>
#include<vector>

using namespace std;

int main()
{
    vector<string> patterns = {"tst", "test", "tt","tt"};
    string text ="tsttsteststestt";

    Aho ahoAlg;
    int val = 2;
    for (int i = 0; i < patterns.size(); i++)
    {
        ahoAlg.AddString(patterns[i], i); // Add all patterns to the structure
    }

    // Prepare algorithm for work (calculates all links in the structure):
    ahoAlg.PrepareAho();

    // Process the text. Output might be different; in my case, it's a count of
    // matches. We could instead return a structure with more detailed information.
    int countOfMatches = ahoAlg.ProcessString(text);

    cout<< countOfMatches <<endl;
    return 0;
}
