#ifndef TSPPROBLEM_H
#define TSPPROBLEM_H

#include "Graph.h"

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
