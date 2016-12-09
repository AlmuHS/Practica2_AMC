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


#include "../include/TSPProblem.h"

using namespace std;

TSPProblem::TSPProblem()
{
    //ctor

}


void TSPProblem::setGraph(Graph G)
{
    this->G = G;
}

void TSPProblem::GenSet()
{
    node_vector = G.get_NodeList();
    node_set.clear();
    for(unsigned int i = 0; i < node_vector.size(); i++)
    {
        node_set.insert(node_vector[i]);
    }
}


int TSPProblem::SimpleSolution()
{
    int numnodes = G.get_numNodes();
    long long sum_distance = 999999999999;
    long long new_distance = 0;

    while( next_permutation(node_vector.begin(), node_vector.end()) )
    {
        queue<int> new_solution;

        for(int i = 0; i < numnodes - 1; i++)
        {
            if(node_vector[i] < node_vector[i+1]){
                new_distance += G.get_distance(node_vector[i], node_vector[i+1]);
            }
            else{
                new_distance += G.get_distance(node_vector[i+1], node_vector[i]);
            }
            cout<<node_vector[i]<<" - ";
            new_solution.push(node_vector[i]);
        }//End for
        cout<<new_distance<<endl<<endl;

        if(new_distance < sum_distance)
        {
            sum_distance = new_distance;
            solution_queue = new_solution;
        }//End if
        new_distance = 0;
    }//End while

    return sum_distance;
}


int TSPProblem::GreedySolution()
{
    int numnodes = G.get_numNodes();
    long long minimal = 9999999999999;
    long long new_min;
    long long sum_distance = 999999999;
    int i = 0;
    int pos_min = 0;

    long long new_distance = 0;

    for(int k = 0; k < numnodes; k++)
    {
        queue<int> new_solution;
        GenSet();
        new_distance = 0;
        i = 0;

        new_solution.push(node_vector[k] + 1);
        node_set.erase(node_vector[k]);


        while(!node_set.empty())
        {
            for(int j = 0; j < numnodes; j++)
            {
                if(node_set.count(node_vector[j]) > 0)
                {

                    if(j < i) new_min =  G.get_distance(node_vector[j], node_vector[i]);
                    else new_min = G.get_distance(node_vector[i], node_vector[j]);

                    if(new_min < minimal)
                    {
                        minimal = new_min;
                        pos_min = j;
                    }
                }//end if node_set
            }//end for j
            //cout<<i + 1<<" - "<<pos_min + 1<<endl;
            i = pos_min;

            node_set.erase(node_vector[pos_min]);
            new_solution.push(node_vector[pos_min] + 1);
            new_distance += minimal;
            minimal = 999999999999;
        }//end while

        if(new_distance < sum_distance)
        {
            sum_distance = new_distance;
            solution_queue = new_solution;
        }

        new_distance = 0;

    }

    return sum_distance;
}

queue<int> TSPProblem::get_solution()
{
    return solution_queue;
}
