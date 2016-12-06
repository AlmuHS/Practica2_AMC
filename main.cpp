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


void test_MLP(int numnodes)
{
    GenGraph GenG;
    MinLenghtProblem MLP;
    long minimal_lenght;
    int node_pair[2];

    cout<<"Generating graph..."<<endl;

    GenG.Generate_graph(numnodes);
    MLP.set_graph(GenG.getGraph());
    minimal_lenght = MLP.SimpleSolution(node_pair);

    cout<<"The minimal lenght points are: "<<node_pair[0]<<" and "<<node_pair[1]<<endl;
    cout<<"The minimal lenght is "<<minimal_lenght<<endl;

    GenG.SortGraph();
    MLP.set_graph(GenG.getGraph());
    minimal_lenght = MLP.DCSolution();

    cout<<"The minimal lenght is "<<minimal_lenght<<endl;
}

void test_TSP(string file)
{
    queue<int> solution;
    long min_distance;
    TSPProblem TSP;

    GenGraph GenG(file);
    GenG.GenGraphFromFile();
    TSP.setGraph(GenG.getGraph());
    TSP.GenSet();
    min_distance = TSP.GreedySolution();
    solution = TSP.get_solution();

    cout<<"The minimal way is ";
    int sol_size = solution.size();

    for(int i = 0; i < sol_size; i++)
    {
        cout<<solution.front()<<" - ";
        solution.pop();
    }
    cout<<endl<<"The minimal way lenght is "<<min_distance<<endl;

}


int main()
{
    int option;
    int num_file;
    int numnodes;

    do
    {

        cout<<"Complex Algorithms study"<<endl
            <<"************************"<<endl
            <<"1. Test Minimal Lenght Points Problem"<<endl
            <<"2. Test Travel Salesman Problem"<<endl
            <<"3. Exit"<<endl
            <<"Select Option: ";
        cin>>option;

        switch(option)
        {
        case 1:
            cout<<"Introduce number of nodes: ";
            cin>>numnodes;
            test_MLP(numnodes);
            break;

        case 2:
            cout<<"Select file: "<<endl
                <<"1. berlin52"<<endl
                <<"2. ch130"<<endl
                <<"3. d493"<<endl
                <<"Enter option: ";
            cin>>num_file;

            switch(num_file)
            {
            case 1:
                test_TSP("berlin52.tsp");
                break;

            case 2:
                test_TSP("ch130.tsp");
                break;

            case 3:
                test_TSP("d493.tsp");
                break;
            }
            break;
        }
    }
    while(option != 3);

    return 0;
}
