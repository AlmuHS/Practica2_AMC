#ifndef MINLENGHTPROBLEM_H
#define MINLENGHTPROBLEM_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Graph.h"
#include "GenGraph.h"

class MinLenghtProblem
{
private:
    Graph G;
    GenGraph GenG;

public:
    MinLenghtProblem();
    void set_graph(Graph G);
    void Generate_graph();
    void Generate_XSortedGraph();
    float SimpleSolution(int node_pair[2]);
    float DCSolution();
    void SortGraph();
};

#endif // MINLENGHTPROBLEM_H
