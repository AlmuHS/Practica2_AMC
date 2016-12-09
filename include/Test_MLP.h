#ifndef TEST_MLP_H
#define TEST_MLP_H

#include <ctime>
#include <chrono>

#include "GenGraph.h"
#include "MinLenghtProblem.h"
#include "Mtime.h"

class Test_MLP
{

    int numnodes;
    MinLenghtProblem MLP;

    public:
        Test_MLP();
        void set_numnodes(int n_nodes);
        void RandomDemo();
        double Search(Graph G, int method);
        void BestCase(int method);
        void MediumCase(int method);
        void WorstCase(int method);
};

#endif // TEST_MLP_H
