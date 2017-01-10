// *** ADDED BY HEADER FIXUP ***
#include <istream>
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

/*
*This class implements two algorithms to solve the minimal lenght pair problem
*using Simple (exhaustive) solution and Divide and Conquer solution
*/


#ifndef MINLENGHTPROBLEM_H
#define MINLENGHTPROBLEM_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Graph.h"
#include "GenGraph.h"
#include <ctime>
#include <algorithm>

class MinLenghtProblem
{
private:
    Graph G;
    GenGraph *GenG;

public:
	//Constructor
    MinLenghtProblem(int capacity);

	//Destructor
    ~MinLenghtProblem();

	//set a graph from parameter
    void set_graph(const Graph &G);

	//Execute exhaustive MLP algorithm
    int SimpleSolution(int node_pair[2]);

	//Main method to recursive DC algorithm
    int DCSolution(int node_pair[2]);

};

#endif // MINLENGHTPROBLEM_H
