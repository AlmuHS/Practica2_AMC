#ifndef TSPPROBLEM_H
#define TSPPROBLEM_H

#include "Graph.h"
#include "GenGraph.h"

#include <fstream>
#include <set>
#include <string>
#include <queue>

using namespace std;

class TSPProblem
{
    Graph G;
    GenGraph GenG;
    set<int> node_set;
    string file_name;
    ifstream file;
    vector<int> node_vector;
    queue<int> solution_queue;
    public:
        TSPProblem(string file_n);
        void GenSet();
        void setGraph(Graph G);
        void GenGraphFromFile();
        void initialize_set();

        float SimpleSolution();
        float GreedySolution();
};

#endif // TSPPROBLEM_H
