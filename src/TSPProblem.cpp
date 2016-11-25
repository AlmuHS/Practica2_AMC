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
    for(unsigned int i = 0; i < node_vector.size(); i++){
        node_set.insert(node_vector[i]);
    }
}

float TSPProblem::SimpleSolution(){
    float minimal, new_min, length;
    int numnodes = G.get_numNodes();
    int copy_i, copy_j;


    for(int i = 0; i < numnodes; i++){
        copy_i = i;
        for(int j = 0; j < numnodes; j++){
            if(i != j && node_set.count(node_vector[j]) != 0){

                if(j < i) new_min = G.get_distance(node_vector[i], node_vector[j]);
                else new_min = G.get_distance(node_vector[j], node_vector[i]);

                if(new_min < minimal){
                    minimal = new_min;
                    i = j;
                    j = 0;
                    copy_j = j;
                    node_set.erase(node_vector[j]);
                    solution_queue.push(node_vector[j]);
                }
            }
            //if(node_se)
        }
    }
    return minimal;
}


float TSPProblem::GreedySolution(){
    int numnodes = G.get_numNodes();
    float minimal = G.get_distance(node_vector[0], node_vector[1]);
    float new_min;
    float sum_distance = 0;
    int i = 0;

    while(!node_set.empty()){
        for(int j = 0; j < numnodes; j++){
            if( j != i && node_set.count(node_vector[j]) != 0){
                if(j < i) new_min =  G.get_distance(node_vector[j], node_vector[i]);
                else new_min = G.get_distance(node_vector[i], node_vector[j]);

                if(new_min < minimal){
                    cout<<i<<" - "<<j<<endl;
                    i = j;
                    new_min = minimal;
                    node_set.erase(node_vector[j]);
                    solution_queue.push(node_vector[j]);
                    sum_distance += new_min;
                    break;
                }//end if new_min
            }//end if node_set
        }//end for j
        i++;
    }//end while
    return sum_distance;
}

queue<int> TSPProblem::get_solution(){
    return solution_queue;
}
