#include "../include/Test_MLP.h"

#define DC 2
#define SIMPLE 1
#define REPEAT 15

using namespace std;
using namespace std::chrono;

Test_MLP::Test_MLP()
{
    //ctor
}

void Test_MLP::set_numnodes(int n_nodes){
    numnodes = n_nodes;
}


void Test_MLP::RandomDemo(int n_nodes){
    GenGraph GenG;
    long minimal_lenght;
    int node_pair[2];

    GenG.Generate_graph(n_nodes);
    MLP.set_graph(GenG.getGraph());
    minimal_lenght = MLP.SimpleSolution(node_pair);

    cout<<"The minimal lenght points are: "<<node_pair[0]<<" and "<<node_pair[1]<<endl;
    cout<<"The minimal lenght is "<<minimal_lenght<<endl;

    GenG.SortGraph();
    MLP.set_graph(GenG.getGraph());
    minimal_lenght = MLP.DCSolution();

    cout<<"The minimal lenght is "<<minimal_lenght<<endl;
}

#if defined _WIN32 || defined _WIN64

double Test_MLP::Search(Graph G, int method){
    Mtime counter;
    LARGE_INTEGER t_ini, t_fin;

    MLP.set_graph(G);


    if(method == SIMPLE){
        QueryPerformanceCounter(&t_ini);
        MLP.SimpleSolution(solution);
        QueryPerformanceCounter(&t_fin);
    }
    else{
        QueryPerformanceCounter(&t_ini);
        MLP.DCSolution();
        QueryPerformanceCounter(&t_fin);
    }

    return (counter.performancecounter_diff(&t_fin, &t_ini)*1000000);
}

#elif defined __linux__ || defined __unix__

double Test_MLP::Search(Graph G, int method){
    duration<double> interval;
    int solution[2];
    high_resolution_clock::time_point t_ini, t_fin;

    MLP.set_graph(G);

    if(method == SIMPLE){
        t_ini = high_resolution_clock::now();
        MLP.SimpleSolution(solution);
        t_fin = high_resolution_clock::now();
    }
    else{
        t_ini = high_resolution_clock::now();
        MLP.DCSolution();
        t_fin = high_resolution_clock::now();
    }

    interval = duration_cast<duration<double>>(t_fin - t_ini)*1000;

    return (interval.count()*1000000);
}

#endif // __linux__

void Test_MLP::BestCase(int method){
    GenGraph GenG;
    pair<float, float> p;
    int solution[2];
    double seconds, time;

    int StartLenght, EndLenght, increase;

    StartLenght = 10;
    increase = 5;
    EndLenght = 30;

    for(int j = StartLenght; j < EndLenght; j+=increase){

        numnodes = j;

        for(int i = 0; i < REPEAT; i++){
            p.first = 0.5;
            p.second = 1.2;

            GenG.add_pair(p);

            p.first = 0.05;
            p.second = 0.2;

            GenG.add_pair(p);

            GenG.Generate_graph(numnodes - 2);

            seconds = Search(GenG.getGraph(), method);
        }

        time = seconds/REPEAT;

        cout<<time<<endl;
    }

}

void Test_MLP::MediumCase(int method){
    GenGraph GenG;
    int solution[2];
    double seconds, time;

    int StartLenght, EndLenght, increase;

    StartLenght = 10;
    increase = 10;
    EndLenght = 50;

    for(int j = StartLenght; j < EndLenght; j+=increase){

        numnodes = j;

        for(int i = 0; i < REPEAT; i++){
            GenG.Generate_graph(numnodes);
            seconds = Search(GenG.getGraph(), method);
        }

        time = seconds / REPEAT;

        cout<<time<<endl;
    }
}


void Test_MLP::WorstCase(int method){
    GenGraph GenG;
    int solution[2];
    pair<float, float> p;
    double seconds, time;

    int StartLenght, EndLenght, increase;

    StartLenght = 10;
    increase = 10;
    EndLenght = 50;

    for(int j = StartLenght; j < EndLenght; j += increase){

        for(int i = 0; i < REPEAT; i++){
            p.first = 0.01;
            p.second = 0.1;

            GenG.add_pair(p);

            GenG.Generate_graph(numnodes - 2);

            p.first = 0.02;
            p.second = 0.5;

            GenG.add_pair(p);

            GenG.create_graph();
            seconds = Search(GenG.getGraph(), method);
        }

        time = seconds / REPEAT;

        cout<<time<<endl;
    }
}
