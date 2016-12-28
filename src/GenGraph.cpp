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



#include "../include/GenGraph.h"

using namespace std;

GenGraph::GenGraph(string file_n): file(file_n.c_str(), ios::in)
{
    //ctor
    file_name = file_n;
    G = new Graph;
}

GenGraph::~GenGraph(){
    delete G;
}

void GenGraph::add_edge(node n1, node n2){
    int distance = rint(sqrt(pow(n1.x - n2.x, 2) + pow(n1.y - n2.y, 2)));

    G->set_distance(n1.n, n2.n, distance);
}

Graph GenGraph::getGraph(){
    return *G;
}

void GenGraph::add_pair(pair<float, float> p){
    node_list.push_back(p);
}


void GenGraph::create_graph(){
    struct node n1;
    struct node n2;

    for(unsigned int i = 0; i < node_list.size(); i++){
        for(unsigned int j = i + 1; j <= node_list.size(); j++){
            if(i != j){
                n1.n = i;
                n2.n = j;
                n1.x = node_list[i].first;
                n1.y = node_list[i].second;
                n2.x = node_list[j].first;
                n2.y = node_list[j].second;

                add_edge(n1, n2);
            }
        }
        if((unsigned) G->get_numNodes() < node_list.size())
            G->add_node(n1.n);
    }
}


void GenGraph::xSort_nodelist(){
    sort(node_list.begin(), node_list.end());
}

void GenGraph::SortGraph(){
    xSort_nodelist();
    create_graph();
}


void GenGraph::Generate_graph(int numnodes)
{
    pair<float, float> n1;



    for(int i = 0; i < numnodes; i++)
    {
        n1.first = rand()%100000 + 100;
        n1.second = 2*i + rand()%5000 + 50;

        add_pair(n1);
    }

    create_graph();
}

void GenGraph::Generate_XSortedGraph()
{
    pair<float, float> n1;
    cout<<"pos x\tpos y"<<endl;

    for(int i = 0; i < 5; i++)
    {
        n1.first = log10(rand());
        n1.second = sqrt(rand()/20);

        cout<<n1.first<<"\t"<<n1.second<<"\t\t"<<endl;

        add_pair(n1);
    }

    xSort_nodelist();
    create_graph();
}

void GenGraph::GenGraphFromFile(){
    string line;
    int n = 1;
    pair<float, float> n1;

    //skip file headers
    getline(file, line);
    getline(file, line);
    getline(file, line);
    getline(file, line);
    getline(file, line);
    getline(file, line);

    while(n != 0){
        file >> n;
        if(n != 0){
            file >> n1.first;
            file >> n1.second;
            cout<<n<<"\t"<<n1.first<<"\t"<<n1.second<<endl;
            add_pair(n1);
        }
    }

    create_graph();}


void GenGraph::show_graph(){
    cout<<"node\tpos x\tpos y"<<endl;

    for(unsigned int i = 0; i < node_list.size(); i++){
        cout<<i+1<<"\t"<<node_list[i].first<<"\t"<<node_list[i].second<<"\t\t"<<endl;
    }
}

vector<pair<float, float> > GenGraph::getPairList(){
     return node_list;
}
