#ifndef TEST_TSP_H
#define TEST_TSP_H

#include "TSPProblem.h"

class Test_TSP
{
    TSPProblem TSP;

    public:
        Test_TSP();

        void TestFile(string file, int method);
        void TestRandom(int numnodes, int method);
};

#endif // TEST_TSP_H
