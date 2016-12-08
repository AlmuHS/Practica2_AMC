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



#ifndef GENGRAPH_H
#define GENGRAPH_H

#include<iostream>
#include<utility>
#include<vector>
#include "Graph.h"
#include "QuickSort.h"
#include <fstream>


using namespace std;

class GenGraph
{
    Graph G;
    vector<pair<float, float> > node_list;
    QuickSort Q;
    ifstream file;
    ofstream fout;
    string file_name;

public:
    GenGraph(string file_n = "");
    void add_pair(pair<float, float> p);
    void add_edge(node n1, node n2);
    void create_graph();
    void GenGraphFromFile();
    void xSort_nodelist();
    Graph getGraph();
    void SortGraph();
    void Generate_graph(int numnodes);
    void Generate_XSortedGraph();
};

#endif // GENGRAPH_H
