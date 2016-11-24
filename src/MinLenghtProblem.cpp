#include "../include/MinLenghtProblem.h"

using namespace std;

MinLenghtProblem::MinLenghtProblem(){
    //this->G = G;
    srand(time(0));
}

void MinLenghtProblem::set_graph(Graph G){
    this->G = G;
}

void MinLenghtProblem::Generate_graph()
{
    pair<float, float> n1;

    cout<<"pos x\t\tpos y"<<endl;

    for(int i = 0; i < 1000; i++)
    {
        n1.first = log10(rand());
        n1.second = sqrt(rand()/20);

        cout<<n1.first<<"\t"<<n1.second<<"\t\t"<<endl;

        GenG.add_pair(n1);
    }

    GenG.create_graph();

    G = GenG.getGraph();
}

void MinLenghtProblem::Generate_XSortedGraph()
{
    pair<float, float> n1;

    cout<<"pos x\t\tpos y"<<endl;

    for(int i = 0; i < 20; i++)
    {
        n1.first = log10(rand());
        n1.second = sqrt(rand()/20);

        cout<<n1.first<<"\t"<<n1.second<<"\t\t"<<endl;

        GenG.add_pair(n1);
    }

    GenG.xSort_nodelist();
    GenG.create_graph();

    G = GenG.getGraph();
}


float MinLenghtProblem::SimpleSolution(int node_pair[2])
{
    vector<int> nodelist = G.get_NodeList();
    int numnodes = nodelist.size();
    float minimal = G.get_distance(nodelist[0], nodelist[1]);
    node_pair[0] = nodelist[0];
    node_pair[1] = nodelist[1];

    cout<<"Number of nodes: "<<numnodes<<endl;

    for(int i = 0; i < numnodes; i++)
    {
        for(int j = i + 1; j < numnodes; j++)
        {
            if(nodelist[i] != nodelist[j]){
                float new_min = G.get_distance(nodelist[i], nodelist[j]);
                cout<<"Distance "<<nodelist[i]<<" - "<<nodelist[j]<<": "<<new_min<<endl;
                if(new_min < minimal)
                {
                    minimal = new_min;
                    node_pair[0] = nodelist[i];
                    node_pair[1] = nodelist[j];
                }
            }
        }
    }
    return minimal;
}

void MinLenghtProblem::GenSortGraph(){
    GenG.xSort_nodelist();
    GenG.create_graph();
    G = GenG.getGraph();
}

float MinLenghtProblem::DCSolution()
{
    vector<int> nodelist = G.get_NodeList();
    float minimal = G.get_distance(nodelist[0], nodelist[1]);
    for(int i=1; i<nodelist.size(); i++){
        if(nodelist[i] != 0){
            float new_minimal = G.get_distance(nodelist[0], nodelist[i]);
            cout<<"Distance "<<nodelist[0]<<" - "<<nodelist[i]<<": "<<new_minimal<<endl;
            if(new_minimal < minimal) minimal = new_minimal;
        }
    }
    return minimal;
}


