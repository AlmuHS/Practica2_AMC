#ifndef TSPPROBLEM_H
#define TSPPROBLEM_H

#include "Graph.h"
#include "GenGraph.h"

class TSPProblem
{
    Graph G;
    GenGraph GenG;

    public:
        TSPProblem();
        void setGraph(Graph G);
        void ReadFile();

        float SimpleSolution();
};

#endif // TSPPROBLEM_H
