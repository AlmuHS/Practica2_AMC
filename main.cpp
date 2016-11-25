#include <iostream>
#include "include/GenGraph.h"
#include "include/MinLenghtProblem.h"
#include "include/TSPProblem.h"

using namespace std;


void test_MLP(){
    GenGraph GenG;
    MinLenghtProblem MLP;
    float minimal_lenght;
    int node_pair[2];

    cout<<"Generating graph..."<<endl;

    MLP.Generate_graph();
    minimal_lenght = MLP.SimpleSolution(node_pair);

    cout<<"The minimal lenght points are: "<<node_pair[0]<<" and "<<node_pair[1]<<endl;
    cout<<"The minimal lenght is "<<minimal_lenght<<endl;

    MLP.SortGraph();
    minimal_lenght = MLP.DCSolution();

    cout<<"The minimal lenght is "<<minimal_lenght;
}



int main()
{
    GenGraph GenG;
    queue<int> solution;
    float min_distance;

    //test_MLP();

    TSPProblem TSP("berlin52.tsp");
    TSP.GenGraphFromFile();
    TSP.GenSet();
    min_distance = TSP.GreedySolution();
    solution = TSP.get_solution();

    cout<<"The minimal way lenght is "<<min_distance<<endl;

    return 0;
}
