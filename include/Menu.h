#ifndef MENU_H
#define MENU_H

#include "Test_MLP.h"
#include "Test_TSP.h"

#if defined _WIN32 || defined _WIN64
    #include <windows.h>
#elif defined __unix__ || defined __linux__
    #include <unistd.h>
    #include <term.h>
#endif // defined

class Menu
{
    Test_MLP T_MLP;
    Test_TSP T_TSP;

    public:
        Menu();

        void MainMenu();
        void MLP_Menu();
        void TSP_Menu();
        void clearscreen();
};

#endif // MENU_H
