#include "Vertex.h"

Vertex::Vertex()
{
//        Children = new Hashtable();
		Leaf = false;
		Parent = -1;
		SuffixLink = -1;
		//WordID = -1;
		EndWordLink= -1;
		//val = -1;
}

Vertex::~Vertex()
{
    //dtor
}
