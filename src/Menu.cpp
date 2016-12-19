#include "../include/Menu.h"

Menu::Menu()
{
    //ctor
}

#if defined _WIN32 || defined _WIN64

void Menu::clearscreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition( hStdOut, homeCoords );
}

#elif defined __linux__ || defined __unix__
    void Menu::clearscreen()
    {
      if (!cur_term)
      {
        int result;
        setupterm( NULL, STDOUT_FILENO, &result );
        if (result <= 0) return;
      }
      putp( tigetstr( "clear" ) );
    }
#endif



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

int Menu::MLP_AlgorithmMenu(){
    int algorithm;

    cout<<"Select algorithm: "<<endl
        <<"1. Simple"<<endl
        <<"2. Divide and Conquer"<<endl
        <<"Enter algorithm: ";
    cin>>algorithm;

    return algorithm;
}

int Menu::TSP_AlgorithmMenu(){
    int algorithm;

    cout<<"Select algorithm: "<<endl
        <<"1. Simple"<<endl
        <<"2. Greedy"<<endl
        <<"Enter algorithm: ";
    cin>>algorithm;

    return algorithm;
}

string Menu::FileMenu(){
    string filename;
    int num_file;

    cout<<"Select file: "<<endl
        <<"1. berlin52"<<endl
        <<"2. ch130"<<endl
        <<"3. d493"<<endl
        <<"4. Other"<<endl
        <<"Enter option: ";
    cin>>num_file;

    switch(num_file){
        case 1:
            filename = "berlin52.tsp";
        break;

        case 2:
            filename = "ch130.tsp";
        break;

        case 3:
            filename = "d493.tsp";
        break;

        case 4:
            cout<<"Enter file path: ";
            cin>>filename;
        break;
    }

    return filename;

}

void Menu::MLP_Menu(){
    int numnodes, option, algorithm;
    string filename;

    clearscreen();

    cout<<"Minimal Lenght Problem"<<endl
        <<"-----------------------"<<endl<<endl
        <<"1. Test Algorithms"<<endl
        <<"2. Best Case Times"<<endl
        <<"3. Medium Case Times"<<endl
        <<"4. Worst Case Times"<<endl
        <<"5. Test from File"<<endl
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
            algorithm = MLP_AlgorithmMenu();
            T_MLP.BestCase(algorithm);
        break;

        case 3:
            algorithm = MLP_AlgorithmMenu();
            T_MLP.MediumCase(algorithm);
        break;

        case 4:
            algorithm = MLP_AlgorithmMenu();
            T_MLP.WorstCase(algorithm);
        break;

        case 5:
            filename = FileMenu();

            algorithm = MLP_AlgorithmMenu();

            T_MLP.TestFile(filename, algorithm);

        break;
    }
}

void Menu::TSP_Menu(){
    int algorithm, option, numnodes;
    string filename;

    clearscreen();

    cout<<"Travel Salesman Problem"<<endl
        <<"------------------------"<<endl<<endl
        <<"1. Test Random"<<endl
        <<"2. Test from File"<<endl
        <<"Enter option: ";
    cin>>option;

    clearscreen();

    if(option == 1){
        cout<<"Introduce number of nodes: ";
        cin>>numnodes;

        algorithm = TSP_AlgorithmMenu();


        T_TSP.TestRandom(numnodes, algorithm);
    }
    else{

        filename = FileMenu();

        algorithm = TSP_AlgorithmMenu();

        T_TSP.TestFile(filename, algorithm);
    }//End else
}
