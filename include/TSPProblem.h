#ifndef TSPPROBLEM_H
#define TSPPROBLEM_H

#include "Graph.h"
#include "GenGraph.h"

#include <set>
#include <queue>

using namespace std;

class TSPProblem
{
    Graph G;
    GenGraph GenG;
    set<int> node_set;


    vector<int> node_vector;
    queue<int> solution_queue;
    public:
        TSPProblem();
        void GenSet();
        void setGraph(Graph G);
        queue<int> get_solution();

        float SimpleSolution();
        float GreedySolution();
};

#endif // TSPPROBLEM_H
