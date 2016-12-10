#ifndef MENU_H
#define MENU_H

#include "Test_MLP.h"
#include "Test_TSP.h"


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
