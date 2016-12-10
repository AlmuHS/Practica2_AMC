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

MinLenghtProblem::MinLenghtProblem(){
    srand(time(0));
}

void MinLenghtProblem::set_graph(Graph G){
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
                node_pair[0] = nodelist[i];
                node_pair[1] = nodelist[j];
            }
        }
    }
    return minimal;
}

int MinLenghtProblem::DCSolution()
{
    GenG.SortGraph();
    vector<int> nodelist = G.get_NodeList();
    int numnodes = G.get_numNodes();
    long minimal = 9999999999999;
    long new_minimal = 0;
    for(int i = 1; i < numnodes; i++){
        new_minimal = G.get_distance(nodelist[0], nodelist[i]);
        //cout<<"Distance "<<nodelist[0]<<" - "<<nodelist[i]<<": "<<new_minimal<<endl;
        if(new_minimal < minimal) minimal = new_minimal;
    }
    return minimal;
}
