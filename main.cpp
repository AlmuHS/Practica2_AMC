#include <iostream>
#include "include/GenGraph.h"
#include "include/MinLenghtProblem.h"

using namespace std;

int main()
{
    GenGraph GenG;
    int node_pair[2];
    float minimal_lenght;
    struct node n1;
    struct node n2;
    struct node n3;

    n1.n = 0;
    n1.x = 24.7;
    n1.y = 1500.92;

    n2.n = 1;
    n2.x = 1;
    n2.y = 1;

    n3.n = 3;
    n3.x = 20;
    n3.y = 30;

    cout<<"Generando grafo..."<<endl;

    GenG.add_edge(n1, n2);
    GenG.add_edge(n1, n3);
    GenG.add_edge(n2, n3);

    MinLenghtProblem MLP(GenG.getGraph());

    minimal_lenght = MLP.SimpleSolution(node_pair);

    cout<<"Los puntos mas cercanos son: "<<node_pair[0]<<" y "<<node_pair[1]<<endl;
    cout<<"La distancia minima es "<<minimal_lenght;

    return 0;
}
