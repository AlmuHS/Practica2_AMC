#include <iostream>
#include "include/GenGraph.h"
#include "include/MinLenghtProblem.h"

using namespace std;

int main()
{
    GenGraph GenG;
    MinLenghtProblem MLP;

    int node_pair[2];
    float minimal_lenght;
    /*pair<float, float> n;

    n.first = 24.7;
    n.second = 1500.92;

    GenG.add_pair(n);

    n.first = 1;
    n.second = 1;

    GenG.add_pair(n);

    n.first = 4;
    n.second = 20;

    GenG.add_pair(n);

    n.first = 3.14;
    n.second = 985000;

    GenG.add_pair(n);

    n.first = 13;
    n.second = 0;

    GenG.add_pair(n);*/

    cout<<"Generating graph..."<<endl;

    MLP.Generate_graph();
    minimal_lenght = MLP.SimpleSolution(node_pair);

    cout<<"The minimal lenght points are: "<<node_pair[0]<<" and "<<node_pair[1]<<endl;
    cout<<"The minimal lenght is "<<minimal_lenght<<endl;

    MLP.GenSortGraph();
    minimal_lenght = MLP.DCSolution();

    cout<<"The minimal lenght is "<<minimal_lenght;

    return 0;
}
