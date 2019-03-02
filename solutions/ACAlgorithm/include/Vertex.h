#ifndef VERTEX_H
#define VERTEX_H

#include <bits/stdc++.h>
#include<map>

using namespace std;
class Vertex
{
    public:
        Vertex();
        virtual ~Vertex();

        // Links to the child vertexes in the trie:
        // Key: A single character
        // Value: The ID of vertex
        map<char, int> Children;

        // Flag that some word from the dictionary ends in this vertex
        bool Leaf;

        // Link to the parent vertex
        int Parent;

        // Char which moves us from the parent vertex to the current vertex
        char ParentChar;

        // Suffix link from current vertex (the equivalent of P[i] from the KMP algorithm)
        int SuffixLink;

        // Link to the leaf vertex of the maximum-length word we can make from the current prefix
        int EndWordLink;

        // If the vertex is the leaf, we store the ID of the word
        int WordID;

    protected:

    private:
};

#endif // VERTEX_H
