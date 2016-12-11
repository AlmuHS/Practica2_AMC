#include "Menu.h"

Menu::Menu()
{
    //ctor
}

void Menu::clearscreen(){
    #if defined _WIN32 || defined _WIN64
        system("cls");
    #elif defined __unix__ || defined __linux__
        system("clear");
    #endif // defined
}

void Menu::MainMenu(){
    int option = 0;
    do
    {

        cout<<"Complex Algorithms study"<<endl
            <<"************************"<<endl
            <<"1. Test Minimal Lenght Points Problem"<<endl
            <<"2. Test Travel Salesman Problem"<<endl
            <<"3. Exit"<<endl
            <<"Select Option: ";
        cin>>option;

        switch(option)
        {
        case 1:
            MLP_Menu();

        break;

        case 2:
            TSP_Menu();
        break;
        }

    }
    while(option != 3);
}

void Menu::MLP_Menu(){
    int numnodes, option, algorithm;

    clearscreen();

    cout<<"Minimal Lenght Problem"<<endl
        <<"-----------------------"<<endl<<endl
        <<"1. Test Algorithms"<<endl
        <<"2. Best Case Times"<<endl
        <<"3. Medium Case Times"<<endl
        <<"4. Worst Case Times"<<endl
        <<"Select Option: ";
    cin>>option;

    clearscreen();

    switch(option){
        case 1:
            cout<<"Introduce number of nodes: ";
            cin>>numnodes;
            T_MLP.RandomDemo(numnodes);
        break;

        case 2:
            cout<<"Select algorithm: "<<endl
                <<"1. Simple"<<endl
                <<"2. Divide and Conquer"<<endl
                <<"Enter algorithm: ";
            cin>>algorithm;

            T_MLP.BestCase(algorithm);
        break;

        case 3:
            cout<<"Select algorithm: "<<endl
                <<"1. Simple"<<endl
                <<"2. Divide and Conquer"<<endl
                <<"Enter algorithm: ";
            cin>>algorithm;

            T_MLP.MediumCase(algorithm);
        break;

        case 4:
            cout<<"Select algorithm: "<<endl
                <<"1. Simple"<<endl
                <<"2. Divide and Conquer"<<endl
                <<"Enter algorithm: ";
            cin>>algorithm;

            T_MLP.WorstCase(algorithm);
        break;
    }


}

void Menu::TSP_Menu(){
    int num_file, algorithm, option, numnodes;

    clearscreen();

    cout<<"Travel Salesman Problem"<<endl
        <<"------------------------"<<endl<<endl
        <<"1. Test Random"<<endl
        <<"2. Test from File"<<endl
        <<"Enter option: ";
    cin>>option;

    if(option == 1){
        cout<<"Introduce number of nodes: ";
        cin>>numnodes;

        cout<<"Select Algorithm"<<endl
            <<"1. Exhaustive"<<endl
            <<"2. Greedy"<<endl
            <<"Enter algorithm: ";
        cin>>algorithm;


        T_TSP.TestRandom(numnodes, algorithm);
    }
    else{

        cout<<"Select file: "<<endl
            <<"1. berlin52"<<endl
            <<"2. ch130"<<endl
            <<"3. d493"<<endl
            <<"Enter option: ";
        cin>>num_file;

        switch(num_file)
        {
            case 1:
                cout<<"Select Algorithm"<<endl
                    <<"1. Exhaustive"<<endl
                    <<"2. Greedy"<<endl
                    <<"Enter algorithm: ";
                cin>>algorithm;

                if(algorithm == 1) T_TSP.TestFile("berlin52.tsp", 1);
                else T_TSP.TestFile("berlin52.tsp", 2);
            break;

            case 2:
                cout<<"Select Algorithm"<<endl
                    <<"1. Exhaustive"<<endl
                    <<"2. Greedy"<<endl
                    <<"Enter algorithm: ";
                cin>>algorithm;

                if(algorithm == 1) T_TSP.TestFile("ch130.tsp", 1);
                else T_TSP.TestFile("ch130.tsp", 2);
            break;

            case 3:
                cout<<"Select Algorithm"<<endl
                    <<"1. Exhaustive"<<endl
                    <<"2. Greedy"<<endl
                    <<"Enter algorithm: ";
                cin>>algorithm;

                if(algorithm == 1) T_TSP.TestFile("d493.tsp", 1);
                else T_TSP.TestFile("d493.tsp", 2);
            break;
        }//End switch
    }//End else
}
