#ifndef GENGRAPH_H
#define GENGRAPH_H

#include<utility>
#include<set>
#include "Graph.h"

using namespace std;

class GenGraph
{
    Graph G;
    set<pair<float, float> > node_set;

public:
    GenGraph();
    void add_pair(pair<float, float> p);
    void add_edge(node n1, node n2);
    void create_graph();
    Graph getGraph();
};

#endif // GENGRAPH_H
