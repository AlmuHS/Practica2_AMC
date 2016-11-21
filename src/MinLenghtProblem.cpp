#include "MinLenghtProblem.h"

void MinLenghtProblem::Generate_graph()
{
    node n1;
    node n2;

    GenGraph GenG;

    for(int i = 0; i < 20; i+=2)
    {
        n1.n = i;
        n1.x = cos(rand());
        n1.y = sqrt(rand());

        n2.n = i + 1;
        n2.x = sin(rand());
        n2.y = rand()/sqrt(2);

        GenG.add_edge(n1, n2);
    }

    G = GenG.getGraph();
}



float MinLenghtProblem::SimpleSolution(int node_pair[2])
{
    vector<int> nodelist = G.get_NodeList();
    int numnodes = G.get_numNodes();
    float minimal = G.get_distance(nodelist[0], nodelist[1]);
    node_pair[0] = nodelist[0];
    node_pair[1] = nodelist[1];

    for(int i = 0; i < numnodes; i++)
    {
        for(int j = 0; j < numnodes; j++)
        {
            float new_min = G.get_distance(nodelist[i], nodelist[j]);
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

void MinLenghtProblem::DCSolution()
{

}


