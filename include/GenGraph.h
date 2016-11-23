#ifndef GENGRAPH_H
#define GENGRAPH_H

#include<iostream>
#include<utility>
#include<vector>
#include "Graph.h"
#include "QuickSort.h"

using namespace std;

class GenGraph
{
    Graph G;
    vector<pair<float, float> > node_list;
    QuickSort Q;

public:
    GenGraph();
    void add_pair(pair<float, float> p);
    void add_edge(node n1, node n2);
    void create_graph();
    void xSort_nodelist();
    Graph getGraph();

};

#endif // GENGRAPH_H
