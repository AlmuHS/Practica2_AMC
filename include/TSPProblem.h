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


#ifndef TSPPROBLEM_H
#define TSPPROBLEM_H

#include "Graph.h"
#include "GenGraph.h"

#include <set>
#include <queue>

using namespace std;

class TSPProblem
{
    Graph G;
    GenGraph GenG;
    set<int> node_set;


    vector<int> node_vector;
    queue<int> solution_queue;
    public:
        TSPProblem();
        void GenSet();
        void setGraph(Graph G);
        queue<int> get_solution();

        float SimpleSolution();
        int GreedySolution();
};

#endif // TSPPROBLEM_H
