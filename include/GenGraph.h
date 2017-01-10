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
#include <fstream>
#include <algorithm>


using namespace std;

struct node{
    int n;
    float x;
    float y;
};

/*
*This class allow generates a fully connected Graph from diferents way inputs
*Also allows update a previously generated graph, and return the results
*/

class GenGraph
{
	Graph *G; //Pointer to Graph object
    vector<pair<float, float> > node_list; //Node list to generate Graph
    ifstream file; //Input file
    string file_name;//Input file's name

public:
	//Constructor
    GenGraph(string file_n = "", int capacity = 100);

	//Destructor
    ~GenGraph();

	//insert a new pair in the graph
    void add_pair(pair<float, float> p);

	//Update distances between two nodes
    void add_edge(node n1, node n2);

	//Generate a new Graph from nodelist
    void create_graph();

	//Generates a new graph from a input nodes file
    void GenGraphFromFile();

	//Return Graph
    Graph getGraph();

	//Generates a new fully random graph
    void Generate_graph(int numnodes);

	//Show node list in screen
    void show_graph();

};

#endif // GENGRAPH_H
