#ifndef GENGRAPH_H
#define GENGRAPH_H

#include<iostream>
#include<utility>
#include<vector>
#include "Graph.h"
#include "QuickSort.h"
#include <fstream>


using namespace std;

class GenGraph
{
    Graph G;
    vector<pair<float, float> > node_list;
    QuickSort Q;
    ifstream file;
    string file_name;

public:
    GenGraph(string file_n = "");
    void add_pair(pair<float, float> p);
    void add_edge(node n1, node n2);
    void create_graph();
    void GenGraphFromFile();
    void xSort_nodelist();
    Graph getGraph();
    void SortGraph();
};

#endif // GENGRAPH_H
