#ifndef GENGRAPH_H
#define GENGRAPH_H

#include<iostream>
#include<utility>
#include<vector>
#include "Graph.h"

using namespace std;

class GenGraph
{
    Graph G;
    vector<pair<float, float> > node_list;

public:
    GenGraph();
    void add_pair(pair<float, float> p);
    void add_edge(node n1, node n2);
    void create_graph();
    Graph getGraph();
};

#endif // GENGRAPH_H
