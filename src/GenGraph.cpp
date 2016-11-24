#include "../include/GenGraph.h"

using namespace std;

GenGraph::GenGraph()
{
    //ctor
}

void GenGraph::add_edge(node n1, node n2){
    float distance = sqrt(pow(n1.x - n2.x, 2) + pow(n1.y - n2.y, 2));

    G.set_distance(n1.n, n2.n, distance);
    G.set_distance(n2.n, n1.n, distance);
}

Graph GenGraph::getGraph(){
    return G;
}

void GenGraph::add_pair(pair<float, float> p){
    node_list.push_back(p);
}


void GenGraph::create_graph(){
    struct node n1;
    struct node n2;

    for(unsigned int i = 0; i < node_list.size(); i++){
        for(unsigned int j = i + 1; j <= node_list.size(); j++){
            if(i != j){
                n1.n = i;
                n2.n = j;
                n1.x = node_list[i].first;
                n1.y = node_list[i].second;
                n2.x = node_list[j].first;
                n2.y = node_list[j].second;

                add_edge(n1, n2);
            }
        }
        G.add_node(n1.n);
    }
}

void GenGraph::xSort_nodelist(){
    Q.quickSort(node_list, 0, node_list.size() - 1);
}
