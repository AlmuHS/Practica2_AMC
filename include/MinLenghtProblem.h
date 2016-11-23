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


public:
    MinLenghtProblem();
    void set_graph(Graph G);
    void Generate_graph();
    float SimpleSolution(int node_pair[2]);
    void DCSolution();
};

#endif // MINLENGHTPROBLEM_H
