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


void TSPProblem::setGraph(Graph G){
    this->G = G;
}

void TSPProblem::GenSet(){
    node_vector = G.get_NodeList();
    for(unsigned int i = 0; i < node_vector.size(); i++){
        node_set.insert(node_vector[i]);
    }
}


float TSPProblem::SimpleSolution(){
    float minimal, new_min, length;
    int numnodes = G.get_numNodes();

    return minimal;
}


int TSPProblem::GreedySolution(){
    int numnodes = G.get_numNodes();
    long minimal = 9999999999999;
    long new_min;
    int sum_distance = 0;
    int i = 0;
    int pos_min = 0;

    solution_queue.push(node_vector[0] + 1);
    node_set.erase(node_vector[0]);

    while(!node_set.empty()){
        for(int j = 0; j < numnodes; j++){
            if(node_set.count(node_vector[j]) > 0){

                if(j < i) new_min =  G.get_distance(node_vector[j], node_vector[i]);
                else new_min = G.get_distance(node_vector[i], node_vector[j]);

                if(new_min < minimal){
                    minimal = new_min;
                    pos_min = j;
                }
            }//end if node_set
        }//end for j
        cout<<i + 1<<" - "<<pos_min + 1<<endl;
        i = pos_min;

        node_set.erase(node_vector[pos_min]);
        solution_queue.push(node_vector[pos_min] + 1);
        sum_distance += minimal;
        minimal = 999999999999;
    }//end while

    sum_distance += G.get_distance(node_vector[0], node_vector[pos_min]);

    return sum_distance;
}

queue<int> TSPProblem::get_solution(){
    return solution_queue;
}
