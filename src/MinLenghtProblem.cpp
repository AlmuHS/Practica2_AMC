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


#include "../include/MinLenghtProblem.h"

using namespace std;

MinLenghtProblem::MinLenghtProblem(int capacity): G(capacity)
{
    srand(time(0));
    GenG = new GenGraph("", capacity);
}

MinLenghtProblem::~MinLenghtProblem()
{
    delete GenG;
}

void MinLenghtProblem::set_graph(const Graph &G)
{
    this->G = G;
}




int MinLenghtProblem::SimpleSolution(int node_pair[2])
{
    vector<int> nodelist = G.get_NodeList();
    int numnodes = nodelist.size();
    long minimal = G.get_distance(nodelist[0], nodelist[1]);
    node_pair[0] = nodelist[0];
    node_pair[1] = nodelist[1];

    //cout<<"Number of nodes: "<<numnodes<<endl;

    for(int i = 0; i < numnodes; i++)
    {
        for(int j = i + 1; j < numnodes; j++)
        {
            long new_min = G.get_distance(nodelist[i], nodelist[j]);
            //cout<<"Distance "<<nodelist[i]<<" - "<<nodelist[j]<<": "<<new_min<<endl;
            if(new_min < minimal)
            {
                minimal = new_min;
                node_pair[0] = nodelist[i] + 1;
                node_pair[1] = nodelist[j] + 1;
            }
        }
    }
    return minimal;
}

int MinLenghtProblem::DCSolution(int node_pair[2])
{
    int row = 0;
    vector<vector<int> > matrix = G.get_matrix();
    vector<vector<int> > copy_matrix = matrix;
    int numnodes = G.get_numNodes();

    //Sort matrix row to row
    for(int i = 0; i < numnodes; i++){
        sort(matrix[i].begin(), matrix[i].end());
    }

    int minimal = 999999;

    //Search the minimal element in the first column
    for(int j= 0; j < numnodes; j++){
        if(matrix[j][0] < minimal){
            minimal = matrix[j][0];
            row = j;
        }
    }

    //Set the first node position to minimal row value
    node_pair[0] = row + 1;

    //Search the second node position in the original matrix, using first node position and minimal length value
    for(int k = 0; k < numnodes; k++){
        if(copy_matrix[row][k] == minimal){
            node_pair[1] = k + 1;
        }
    }

    return minimal;
}






