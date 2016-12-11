#include "../include/Test_TSP.h"

Test_TSP::Test_TSP()
{
    //ctor
}

void Test_TSP::TestRandom(int numnodes, int method){
    queue<int> solution;
    long min_distance;
    ofstream fout;

    GenGraph GenG;
    GenG.Generate_graph(numnodes);

    GenG.show_graph();


    TSP.setGraph(GenG.getGraph());
    TSP.GenSet();

    if(method == 1)
        min_distance = TSP.SimpleSolution();
    else
         min_distance = TSP.GreedySolution();

    solution = TSP.get_solution();

    cout<<"The minimal way is "<<endl;
    int sol_size = solution.size();

    for(int i = 0; i < sol_size; i++)
    {
        int node = solution.front();
        cout<<node<<" - ";
        fout<<node<<endl;

        solution.pop();
    }
    cout<<endl<<"The minimal way lenght is "<<min_distance<<endl;


}

void Test_TSP::TestFile(string file, int method){
    queue<int> solution;
    long min_distance;
    string froute = file + "_route";
    ofstream fout;

    GenGraph GenG(file);
    GenG.GenGraphFromFile();
    TSP.setGraph(GenG.getGraph());
    TSP.GenSet();


    if(method == 1){
        min_distance = TSP.SimpleSolution();
        froute += "Exhaustive.opt";
    }
    else{
        min_distance = TSP.GreedySolution();
        froute += "Greedy.opt";
    }

    fout.open(froute.c_str());

    solution = TSP.get_solution();

    cout<<"The minimal way is "<<endl;
    int sol_size = solution.size();

    fout<<"NAME : "<<file<<".opt.tour"<<endl
        <<"TYPE : TOUR"<<endl
        <<"Dimension: "<<sol_size<<endl
        <<"TOUR_SECTION"<<endl;


    for(int i = 0; i < sol_size; i++)
    {
        int node = solution.front();
        cout<<node<<" - ";
        fout<<node<<endl;

        solution.pop();
    }
    cout<<endl<<"The minimal way lenght is "<<min_distance<<endl;

    fout.close();
}
