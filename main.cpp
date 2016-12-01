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


#include <iostream>
#include "include/GenGraph.h"
#include "include/MinLenghtProblem.h"
#include "include/TSPProblem.h"

using namespace std;


void test_MLP(){
    GenGraph GenG("ch130.tsp");
    MinLenghtProblem MLP;
    long minimal_lenght;
    int node_pair[2];

    cout<<"Generating graph..."<<endl;

    //GenG.GenGraphFromFile();

    GenG.Generate_graph();
    MLP.set_graph(GenG.getGraph());
    minimal_lenght = MLP.SimpleSolution(node_pair);

    cout<<"The minimal lenght points are: "<<node_pair[0]<<" and "<<node_pair[1]<<endl;
    cout<<"The minimal lenght is "<<minimal_lenght<<endl;

    GenG.SortGraph();
    MLP.set_graph(GenG.getGraph());
    minimal_lenght = MLP.DCSolution();

    cout<<"The minimal lenght is "<<minimal_lenght;
}

void test_TSP(){
    queue<int> solution;
    long min_distance;
    TSPProblem TSP;

    GenGraph GenG("d493.tsp");
    GenG.GenGraphFromFile();
    TSP.setGraph(GenG.getGraph());
    TSP.GenSet();
    min_distance = TSP.GreedySolution();
    solution = TSP.get_solution();

    cout<<"The minimal way is ";
    int sol_size = solution.size();

    for(int i=0; i<sol_size; i++){
        cout<<solution.front()<<" - ";
        solution.pop();
    }
    cout<<1;
    cout<<endl<<"The minimal way lenght is "<<min_distance<<endl;

}


int main()
{

    //test_MLP();
    test_TSP();

    return 0;
}
