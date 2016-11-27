#include <iostream>
#include "include/GenGraph.h"
#include "include/MinLenghtProblem.h"
#include "include/TSPProblem.h"

using namespace std;


void test_MLP(){
    GenGraph GenG("d493.tsp");
    MinLenghtProblem MLP;
    float minimal_lenght;
    int node_pair[2];

    cout<<"Generating graph..."<<endl;

    GenG.GenGraphFromFile();
    MLP.set_graph(GenG.getGraph());

    //MLP.Generate_graph();
    minimal_lenght = MLP.SimpleSolution(node_pair);

    cout<<"The minimal lenght points are: "<<node_pair[0]<<" and "<<node_pair[1]<<endl;
    cout<<"The minimal lenght is "<<minimal_lenght<<endl;

    GenG.SortGraph();
    MLP.set_graph(GenG.getGraph());
    minimal_lenght = MLP.DCSolution();

    cout<<"The minimal lenght is "<<minimal_lenght;
}

void test_TSP(){
    queue<int> solution;
    float min_distance;
    TSPProblem TSP;

    GenGraph GenG("d493.tsp");
    GenG.GenGraphFromFile();
    TSP.setGraph(GenG.getGraph());
    TSP.GenSet();
    min_distance = TSP.GreedySolution();
    solution = TSP.get_solution();

    cout<<"The minimal way is ";
    int sol_size = solution.size();

    for(int i=0; i<sol_size; i++){
        cout<<solution.front()<<" - ";
        solution.pop();
    }
    cout<<1;
    cout<<endl<<"The minimal way lenght is "<<min_distance<<endl;

}


int main()
{

    test_MLP();
    //test_TSP();

    return 0;
}
