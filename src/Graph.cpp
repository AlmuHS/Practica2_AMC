#include "Graph.h"

Graph::Graph(int capacity)
{
    maxNodes = capacity;
    numNodes = 0;
    adjacency_matrix.reserve(vector<float>(capacity).capacity());
}

void Graph::add_node(int n1){
    node_list.push_back(n1);
    numNodes++;
}

float Graph::get_distance(int node1, int node2){
    return adjacency_matrix[node1][node2];
}

void Graph::set_distance(int node1, int node2, float distance){
    adjacency_matrix[node1][node2] = distance;
}


int Graph::get_numNodes(){
    return numNodes;
}

vector<int> Graph::get_NodeList(){
    return node_list;
}



