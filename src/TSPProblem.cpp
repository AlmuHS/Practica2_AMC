#include "../include/TSPProblem.h"

using namespace std;

TSPProblem::TSPProblem()
{
    //ctor

}


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
    float minimal = 9999999999999;
    float new_min;
    float sum_distance = 0;
    int i = 0;
    int pos_min = 0;

    solution_queue.push(node_vector[0] + 1);
    node_set.erase(node_vector[0]);

    while(!node_set.empty()){
        for(int j = 1; j < numnodes; j++){
            if(node_set.count(node_vector[j]) > 0){

                if(j < i) new_min =  G.get_distance(node_vector[j], node_vector[i]);
                else new_min = G.get_distance(node_vector[i], node_vector[j]);

                if(new_min < minimal){
                    minimal = new_min;
                    pos_min = j;
                }
            }//end if node_set
        }//end for j
        cout<<i + 1<<" - "<<pos_min + 1<<endl;
        i = pos_min;

        node_set.erase(node_vector[pos_min]);
        solution_queue.push(node_vector[pos_min] + 1);
        sum_distance += minimal;
        minimal = 999999999999;
    }//end while

    sum_distance += G.get_distance(node_vector[0], node_vector[pos_min]);

    return sum_distance;
}

queue<int> TSPProblem::get_solution(){
    return solution_queue;
}
