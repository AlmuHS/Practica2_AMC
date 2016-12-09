#ifndef TEST_MLP_H
#define TEST_MLP_H

#include "GenGraph.h"
#include "MinLenghtProblem.h"

class Test_MLP
{

    int numnodes;
    //GenGraph GenG;
    MinLenghtProblem MLP;

    public:
        Test_MLP();
        void set_numnodes(int n_nodes);
        void RandomDemo();
        void BestCase(int method);
        void MediumCase(int method);
        void WorstCase(int method);
};

#endif // TEST_MLP_H
