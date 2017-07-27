//Jordan Williamson
//CS Fundamentals II
//11AM Class
//Instructor: Roger Priebe
//Filename: life_A00643150.cpp
//Related Files: life.h
//Purpose: To read in an array, and determine if every position in the array 
//lives or dies.
#ifndef life_h
#define life_h

#include <iostream>
#include <fstream>

#include <string>

using namespace std;

//declarations for functions
void populateWorld(string fileName);

void showWorld();

void iterateGeneration();

int numNeighbors(int row, int col);

void applyRules(int neighbors, int row, int col);

#endif
