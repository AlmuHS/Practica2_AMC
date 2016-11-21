#ifndef GENGRAPH_H
#define GENGRAPH_H

#include "Graph.h"

class GenGraph
{
    Graph G;

public:
    GenGraph();

    void add_edge(node n1, node n2);
    Graph getGraph();
};

#endif // GENGRAPH_H
