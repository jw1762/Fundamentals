//life_driver.cpp
//
//Life Driver program
//Roger Priebe 10/10/07 (edited 9/26/08, 2/17/15)
//CS 2308
//

//This file is a driver program for the Life.cpp module.
//This program must work with your implementations Life.h and Life.cpp
//

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "life.h"

const string FILE_NAME = "starting_grid.txt";


using namespace std;

const int NUM_GENERATIONS = 200; //set to a smaller number for debugging

int main()
{
    populateWorld(FILE_NAME);

    showWorld();

    for (int iteration = 0; iteration < NUM_GENERATIONS; iteration++) {

        //clears screen in Linux
        //cout << "\033[2J\033[1;1H" << endl;
        system("CLS");
        iterateGeneration();

        showWorld();
    }

    return 0;
}
