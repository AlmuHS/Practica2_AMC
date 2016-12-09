/* Copyright 2016 Almudena García Jurado-Centurión
    This file is part of Practica2_AMC.

    Practica2_AMC is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Practica2_AMC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Practica2_AMC.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../include/Graph.h"

Graph::Graph(int capacity)
{
    maxNodes = capacity;
    numNodes = 0;
}

Graph::Graph(const Graph &G){
    this->adjacency_matrix = G.adjacency_matrix;
    this->maxNodes = G.maxNodes;
    this->numNodes = G.numNodes;
    this->node_list = G.node_list;
}

void Graph::add_node(int n1){
    if(numNodes == 0){
        adjacency_matrix.clear();
        node_list.clear();
    }
    node_list.push_back(n1);
    numNodes++;
}

int Graph::get_distance(int node1, int node2){
    return adjacency_matrix[node1][node2];
}

void Graph::set_distance(int node1, int node2, int distance){
    adjacency_matrix[node1][node2] = distance;
}


int Graph::get_numNodes(){
    return numNodes;
}

vector<int> Graph::get_NodeList(){
    return node_list;
}



