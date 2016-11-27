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


#ifndef GRAPH_H
#define GRAPH_H

#include<vector>
#include<map>
#include<set>
#include<cmath>

using namespace std;

struct node{
    int n;
    float x;
    float y;
};


class Graph
{
    private:
        int numNodes;
        int maxNodes;

        map<int, map<int,float> > adjacency_matrix;
        vector<int> node_list;

    public:
        Graph(int capacity = 100);
        Graph(const Graph &G);
        void add_node(int n1);
        float get_distance(int node1, int node2);
        void set_distance(int node1, int node2, float distance);
        int get_numNodes();
        vector<int> get_NodeList();
};

#endif // GRAPH_H
