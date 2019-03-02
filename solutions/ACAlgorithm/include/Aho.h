
#include <bits/stdc++.h>
#include<string>
#include<list>
#include<Vertex.h>
#include<queue>
#ifndef AHO_H
#define AHO_H

using namespace std;
class Aho
{
    public:
        Aho();
        virtual ~Aho();
        void AddString(string s, int wordID);
        void PrepareAho();
        void CalcSuffLink(int vertex);
        int ProcessString(string text);
                void Init(void);


    protected:

    private:
        vector<Vertex> Trie;
        vector<int> WordsLength;
        int size;
        int root;
        int start;
        int endindex;

};

#endif // AHO_H
