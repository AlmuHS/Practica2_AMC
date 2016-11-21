#include "../include/GenGraph.h"

GenGraph::GenGraph()
{
    //ctor
}

void GenGraph::add_edge(node n1, node n2){
    float distance = sqrt(pow(n1.x - n2.x, 2) + pow(n1.y - n2.y, 2));

    G.add_node(n1.n);
    G.add_node(n2.n);

    G.set_distance(n1.n, n2.n, distance);
}

Graph GenGraph::getGraph(){
    return G;
}

