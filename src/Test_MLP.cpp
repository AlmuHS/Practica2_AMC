#include "../include/Test_MLP.h"

#define DC 2
#define SIMPLE 1
#define REPEAT 7

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
    GenG.show_graph();

    MLP.set_graph(GenG.getGraph());
    minimal_lenght = MLP.SimpleSolution(node_pair);

    cout<<endl<<"Exhaustive solution"<<endl
        <<"--------------------"<<endl
        <<"The minimal lenght points are: "<<node_pair[0]<<" and "<<node_pair[1]<<endl
        <<"The minimal lenght is "<<minimal_lenght<<endl<<endl;

    GenG.SortGraph();
    MLP.set_graph(GenG.getGraph());
    minimal_lenght = MLP.DCSolution(node_pair);

    cout<<"Divide and Conquer solution"<<endl
        <<"----------------------------"<<endl;

    GenG.show_graph();

    cout<<"The minimal lenght points are: "<<node_pair[0]<<" and "<<node_pair[1]<<endl
        <<"The minimal lenght is "<<minimal_lenght<<endl<<endl;
}

void Test_MLP::TestFile(string file, int method){
    int node_pair[2];
    int solution;
    GenGraph GenG(file);

    GenG.GenGraphFromFile();
    GenG.show_graph();

    if(method == 1){
        MLP.set_graph(GenG.getGraph());
        solution = MLP.SimpleSolution(node_pair);

        cout<<endl<<"Exhaustive solution"<<endl
            <<"--------------------"<<endl
            <<"The minimal lenght points are: "<<node_pair[0]<<" and "<<node_pair[1]<<endl
            <<"The minimal lenght is "<<solution<<endl<<endl;
    }
    else{
        GenG.SortGraph();
        MLP.set_graph(GenG.getGraph());
        solution = MLP.DCSolution(node_pair);

        cout<<"Divide and Conquer solution"<<endl
            <<"----------------------------"<<endl;

        GenG.show_graph();

        cout<<"The minimal lenght points are: "<<node_pair[0]<<" and "<<node_pair[1]<<endl
            <<"The minimal lenght is "<<solution<<endl<<endl;
    }

}


#if defined _WIN32 || defined _WIN64

double Test_MLP::Search(Graph G, int method){
    Mtime counter;
    LARGE_INTEGER t_ini, t_fin;
    int solution[2];

    MLP.set_graph(G);


    if(method == SIMPLE){
        QueryPerformanceCounter(&t_ini);
        MLP.SimpleSolution(solution);
        QueryPerformanceCounter(&t_fin);
    }
    else{
        QueryPerformanceCounter(&t_ini);
        MLP.DCSolution(solution);
        QueryPerformanceCounter(&t_fin);
    }

    return (counter.performancecounter_diff(&t_fin, &t_ini)*1000);
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
        MLP.DCSolution(solution);
        t_fin = high_resolution_clock::now();
    }

    interval = duration_cast<duration<double>>(t_fin - t_ini);

    return (interval.count()*1000000);
}

#endif // __linux__

void Test_MLP::BestCase(int method){
    GenGraph GenG;
    pair<float, float> p;
    int solution[2];
    double seconds, time;
    ofstream fout;

    if(method == 1) fout.open("MLPExhaustive.dat");
    else fout.open("MLPDivide&Conquer.dat");

    cout<<"size\ttime"<<endl;

    for(int j = 0; j < 4; j++){

        if(j == 0) numnodes = 200;
        else if(j == 1) numnodes = 500;
        else if(j == 2) numnodes = 1500;
        else if(j == 3) numnodes = 5000;


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

        cout<<numnodes<<"\t"<<time<<endl;
        fout<<numnodes<<"\t"<<time<<endl;
    }
    fout.close();

}

void Test_MLP::MediumCase(int method){
    GenGraph GenG;
    int solution[2];
    double seconds, time;
    string filename = method + ".dat";
    ofstream fout;

    if(method == 1) fout.open("MLPExhaustive.dat");
    else fout.open("MLPDivide&Conquer.dat");

    cout<<"size\ttime"<<endl;

    for(int j = 0; j < 4; j++){

        if(j == 0) numnodes = 200;
        else if(j == 1) numnodes = 500;
        else if(j == 2) numnodes = 1500;
        else if(j == 3) numnodes = 5000;


        for(int i = 0; i < REPEAT; i++){
            GenG.Generate_graph(numnodes);
            seconds = Search(GenG.getGraph(), method);
        }

        time = seconds / REPEAT;

        cout<<numnodes<<"\t"<<time<<endl;
        fout<<numnodes<<"\t"<<time<<endl;
    }
    fout.close();
}


void Test_MLP::WorstCase(int method){
    GenGraph GenG;
    int solution[2];
    pair<float, float> p;
    double seconds, time;

    cout<<"size\ttime"<<endl;
    string filename = method + ".dat";
    ofstream fout(filename.c_str());

    for(int j = 0; j < 4; j++){

        if(j == 0) numnodes = 200;
        else if(j == 1) numnodes = 500;
        else if(j == 2) numnodes = 1500;
        else if(j == 3) numnodes = 5000;

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

        cout<<numnodes<<"\t"<<time<<endl;
        fout<<numnodes<<"\t"<<time<<endl;
    }
    fout.close();
}

