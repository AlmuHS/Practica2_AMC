#include "../include/Test_MLP.h"

#define DC 2
#define SIMPLE 1

Test_MLP::Test_MLP()
{
    //ctor
    //this->numnodes = numnodes;
}

void Test_MLP::set_numnodes(int n_nodes){
    numnodes = n_nodes;
}

void Test_MLP::RandomDemo(){
    GenGraph GenG;
    long minimal_lenght;
    int node_pair[2];

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


void Test_MLP::BestCase(int method){
    GenGraph GenG;
    pair<float, float> p;
    int solution[2];

    p.first = 0.5;
    p.second = 1.2;

    GenG.add_pair(p);

    p.first = 0.05;
    p.second = 0.2;

    GenG.add_pair(p);

    GenG.Generate_graph(numnodes - 2);

    if(method == SIMPLE){
        MLP.SimpleSolution(solution);
    }
    else{
        MLP.DCSolution();
    }
}

void Test_MLP::MediumCase(int method){
    GenGraph GenG;
    int solution[2];

    GenG.Generate_graph(numnodes);
    if(method == SIMPLE){
        MLP.SimpleSolution(solution);
    }
    else{
        MLP.DCSolution();
    }
}

void Test_MLP::WorstCase(int method){

}
