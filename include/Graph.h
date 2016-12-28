// *** ADDED BY HEADER FIXUP ***
#include <map>
#include <set>
#include <vector>
// *** END ***
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

/*
*This class implements a generic Graph using a distance matrix
*Each matrix position contains the distance between two points, indicated with row and column number
*
*/

class Graph
{
    private:
        int numNodes;//Current number of nodes
        int maxNodes;//Maximal number of nodes in the Graph

        map<int, map<int,int> > adjacency_matrix;//Distance matrix
        vector<int> node_list;

    public:
	/*Default constructor
	 *Includes a parameter to set initial capacity, setted by default to 100 positions
	 */
        Graph(int capacity = 100);
	
	//Copy constructor
        Graph(const Graph &G);
	
	//Insert new node in the Graph
        void add_node(int n1);

	//Get distance between to nodes of the graph
        int get_distance(int node1, int node2);

	//Update distance between two nodes
        void set_distance(int node1, int node2, int distance);

	//Return current number of nodes
        int get_numNodes();

	//Get graph's node list
        vector<int> get_NodeList();
};

#endif // GRAPH_H
