#include "../include/TSPProblem.h"

using namespace std;

TSPProblem::TSPProblem(string file_n): file(file_n, ios::in)
{
    //ctor
    file_name = file_n;
}

void TSPProblem::GenGraphFromFile(){
    string line;
    int n;
    pair<float, float> n1;


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
            GenG.add_pair(n1);
        }
    }

    GenG.create_graph();
    G = GenG.getGraph();}

void TSPProblem::setGraph(Graph G){
    this->G = G;
}

void TSPProblem::GenSet(){
    node_vector = G.get_NodeList();
    for(int i=0; i<node_vector.size(); i++){
        node_set.insert(node_vector[i]);
    }
}

float TSPProblem::SimpleSolution(){
    float minimal;
    int numnodes = G.get_numNodes();
    for(int i = 0; i < numnodes; i++){
        for(int j = i + 1; j < numnodes; j++){
            float new_min = G.get_distance(node_vector[i], node_vector[j]);
            if(new_min < minimal && node_set.count(node_vector[j]) != 0){
                minimal = new_min;
                i = j;
                node_set.erase(node_vector[j]);
                solution_queue.push(node_vector[j]);
            }

        }
    }
}
