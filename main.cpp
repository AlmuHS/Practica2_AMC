#include <iostream>
#include "include/GenGraph.h"
#include "include/MinLenghtProblem.h"

using namespace std;

int main()
{
    MinLenghtProblem MLP;

    cout<<"Generando grafo..."<<endl;

    MLP.Generate_graph();



    return 0;
}
