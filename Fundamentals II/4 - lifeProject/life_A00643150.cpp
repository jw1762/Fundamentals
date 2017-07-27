//Jordan Williamson
//CS Fundamentals II
//11AM Class
//Instructor: Roger Priebe
//Filename: life_A00643150.cpp
//Related Files: life.h
//Purpose: Reads in an array and determines if each position of the array
//lives or dies.
#include <iostream>
#include <fstream>
#include <unistd.h>

#include "life.h"

using namespace std;

const char ALIVE = '1';
const char DEAD = '0';

string *text;
char lives[80];

int numRows;
int numCols;

//Reads in data as a 2D string array.
void populateWorld (string fileName)
{
    const int SIZE_INCREMENT = 3;
    numRows = 0;
    numCols = 0;

    ifstream inFile;
    inFile.open(fileName.data());

    text = new string[SIZE_INCREMENT];

    while ( inFile.getline(lives,80) )
    {
        text [numRows] = lives;
        numCols = text[numRows].length();
        numRows++;

        if (numRows % SIZE_INCREMENT == 0)
        { //time to resize
            string *temptext = new string[numRows + SIZE_INCREMENT];
            for (int i = 0; i < numRows; i++)
            {
                temptext[i] = text[i];
            }

            //free the text memory
            delete [] text;
            text  = temptext;
        }
    }
    inFile.close();
}
void showWorld()
{
    for(int row=0; row < numRows; row++)
    {
        for (int col=0; col < numCols; col++)
        {
            if(text[row][col] == ALIVE)
                cout << "*";
            if (text[row][col] == DEAD)
                cout << "-";
        }
    cout << endl;
    }
    usleep(1000);
}

int numNeighbors(int row, int col)
{
    int neighbors = 0;

    //Checking first column, first row. 3 neighbors.
    if(row == 0 && col == 0)
    {
        if(text[row][col+1] == ALIVE)
        {
            neighbors++;
        }
        if(text[row+1][col+1] == ALIVE)
        {
            neighbors++;
        }
        if(text[row+1][col] == ALIVE)
        {
            neighbors++;
        }
        return neighbors;
    }
    //Checking last column, first row. 3 neighbors.
    if(row == 0 && col == numCols-1)//-1 Because 0 for row/col.
    {
        if(text[row+1][col] == ALIVE)
            neighbors++;
        if(text[row+1][col-1] == ALIVE)
            neighbors++;
        if(text[row][col-1] == ALIVE)
            neighbors++;
        return neighbors;
    }
    //Checking last column, last row. 3 neighbors.
    if(row == numRows-1 && col == numCols-1)//-1 Because 0 for row/col.
    {
        if(text[row][col-1] == ALIVE)
            neighbors++;
        if(text[row-1][col] == ALIVE)
            neighbors++;
        if(text[row-1][col-1] == ALIVE)
            neighbors++;
        return neighbors;
    }
    //Checking first column, last row. 3 neighbors.
    if(row == numRows-1 && col == 0)//-1 Because 0 for row/col.
    {
        if(text[row-1][col] == ALIVE)
            neighbors++;
        if(text[row-1][col+1] == ALIVE)
            neighbors++;
        if(text[row][col+1] == ALIVE)
            neighbors++;
        return neighbors;
    }
    //Checking first row, not a corner. 5 Neighbors.
    if(row == 0 && (col != numCols-1 && col != 0))
    {
        if(text[row][col-1] == ALIVE)
            neighbors++;
        if(text[row][col+1] == ALIVE)
            neighbors++;
        if(text[row+1][col] == ALIVE)
            neighbors++;
        if(text[row+1][col-1] == ALIVE)
            neighbors++;
        if(text[row+1][col+1] == ALIVE)
            neighbors++;
        return neighbors;
    }
    //Checking any left side, 5 neighbors.
    if(col == 0 && (row != 0 && row != numRows-1))
    {
        if(text[row-1][col] == ALIVE)
            neighbors++;
        if(text[row+1][col] == ALIVE)
            neighbors++;
        if(text[row][col+1] == ALIVE)
            neighbors++;
        if(text[row-1][col+1] == ALIVE)
            neighbors++;
        if(text[row+1][col+1] == ALIVE)
            neighbors++;
        return neighbors;
    }
    //Checking any right side. 5 neighbors.
    if(col == numCols-1 && (row != 0 && row != numRows-1))//-1 for row/col starting at 0.
    {
        if(text[row][col-1] == ALIVE)
            neighbors++;
        if(text[row-1][col] == ALIVE)
            neighbors++;
        if(text[row-1][col-1] == ALIVE)
            neighbors++;
        if(text[row+1][col] == ALIVE)
            neighbors++;
        if(text[row+1][col-1] == ALIVE)
            neighbors++;
        return neighbors++;
    }
    //Checking the last row. 5 neighbors.
    if(row == numRows-1 && (col != 0 && col != numCols-1)) //-1 Because row starts at 0.
    {
        if(text[row][col-1] == ALIVE)
            neighbors++;
        if(text[row][col+1] == ALIVE)
            neighbors++;
        if(text[row-1][col+1] == ALIVE)
            neighbors++;
        if (text[row-1][col-1] == ALIVE)
            neighbors++;
        if (text[row-1][col] == ALIVE)
            neighbors++;
        return neighbors;
    }
    //Checking all regular cells. 8 Neighbors.
    if((row != numRows-1 && col != numCols-1) && (row != 0 && col != 0))
    {
        if(text[row][col-1] == ALIVE)
            neighbors++;
        if(text[row][col+1] == ALIVE)
            neighbors++;
        if(text[row-1][col] == ALIVE)
            neighbors++;
        if(text[row-1][col-1] == ALIVE)
            neighbors++;
        if(text[row-1][col+1] == ALIVE)
            neighbors++;
        if(text[row+1][col-1] == ALIVE)
            neighbors++;
        if(text[row+1][col+1] == ALIVE)
            neighbors++;
        if(text[row+1][col] == ALIVE)
            neighbors++;
        return neighbors;
    }
}

void applyRules(int neighbors, int row, int col)
{
    //New life is born with 3 neighbors.
    if (neighbors == 3)
    {
        text[row][col] = ALIVE;
    }
    //The life dies if overcrowded.
    else if (neighbors >= 4)
    {
        text[row][col] = DEAD;
    }
    //Life dies from loneliness if zero or 1 neighbor.
    else if (neighbors == 0 || neighbors == 1)
    {
        text[row][col] = DEAD;
    }
    //Life continues with 3 or 2 neighbors.
    else if ( (neighbors == 3 || neighbors == 2) && text[row][col] == ALIVE )
    {
        text[row][col] = ALIVE;
    }
}

// Note: we create a duplicate of the space in prep for the Life program
void iterateGeneration()
{
    int neighbors = 0;

    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            neighbors = numNeighbors(row, col);
            applyRules(neighbors, row, col);
        }
    }
}
