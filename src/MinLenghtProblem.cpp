#include "../include/MinLenghtProblem.h"

using namespace std;

MinLenghtProblem::MinLenghtProblem(){
    //this->G = G;
}

void MinLenghtProblem::set_graph(Graph G){
    this->G = G;
}

void MinLenghtProblem::Generate_graph()
{
    pair<float, float> n1;
    GenGraph GenG;

    cout<<"pos x\t\tpos y"<<endl;

    for(int i = 0; i < 500; i++)
    {
        n1.first = rand();
        n1.second = sqrt(rand()/20);

        cout<<n1.first<<"\t"<<n1.second<<"\t\t"<<endl;

        GenG.add_pair(n1);
    }

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
        for(int j = 0; j < numnodes; j++)
        {
            if(i != j){
                float new_min = G.get_distance(nodelist[i], nodelist[j]);
                cout<<"Distance "<<i<<" - "<<j<<": "<<new_min<<endl;
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

void MinLenghtProblem::DCSolution()
{

}


