#ifndef GRAPH_H
#define GRAPH_H

#include<vector>
#include<map>
#include<set>
#include<cmath>

using namespace std;

struct node{
    int n;
    float x;
    float y;
};


class Graph
{
    private:
        int numNodes;
        int maxNodes;
        //vector<vector<float> > adjacency_matrix;
        map<int, map<int,float> > adjacency_matrix;
        vector<int> node_list;

    public:
        Graph(int capacity = 100);
        void add_node(int n1);
        float get_distance(int node1, int node2);
        void set_distance(int node1, int node2, float distance);
        int get_numNodes();
        vector<int> get_NodeList();
};

#endif // GRAPH_H
