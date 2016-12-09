
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

// *** ADDED BY HEADER FIXUP ***
#include <istream>
#include <iostream>
#include "include/GenGraph.h"
#include "include/MinLenghtProblem.h"
#include "include/TSPProblem.h"
#include "include/Test_MLP.h"
#include "include/Test_TSP.h"

using namespace std;




void test_TSP(string file)
{
    queue<int> solution;
    long min_distance;
    TSPProblem TSP;


    ofstream fout;

    GenGraph GenG(file);
    GenG.GenGraphFromFile();
    TSP.setGraph(GenG.getGraph());
    TSP.GenSet();
    //min_distance = TSP.GreedySolution();
    min_distance = TSP.SimpleSolution();
    solution = TSP.get_solution();

    cout<<"The minimal way is "<<endl;
    int sol_size = solution.size();

    for(int i = 0; i < sol_size; i++)
    {
        int node = solution.front();
        cout<<node<<" - ";

        solution.pop();
    }
    cout<<endl<<"The minimal way lenght is "<<min_distance<<endl;

}


int main()
{
    int option;
    int num_file;
    int numnodes;
    Test_MLP T_MLP;


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
            /*cout<<"Introduce number of nodes: ";
            cin>>numnodes;
            T_MLP.set_numnodes(numnodes);
            T_MLP.RandomDemo();*/
            T_MLP.BestCase(1);

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
