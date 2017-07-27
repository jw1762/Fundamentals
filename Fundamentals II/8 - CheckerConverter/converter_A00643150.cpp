/*************************************************************
File Name: converter_A00643150.cpp
Author: Jordan Williamson
Date: 5/1/2015
Problem Number: 8
CS 2308 Spring 2015
Instructor: Priebe, Roger

A basic program which takes in two integer numbers as strings,
converts them into integers, then converts the first number into
the base of the second number.
***************************************************************/
#include <iostream>
#include <fstream>
#include <stack>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    if(!argv[1] || !argv[2])
    {
       cout << "Missing number and base conversion! Ending Program..."  << endl;
       return 0;
    }

    int num = atoi(argv[1]);
    int newBase = atoi(argv[2]);

    stack<int> myInts;
    int counter = 0;
    int remainder = 0;

    cout << num << " - base 10." << endl;

    //If converting to binary or octal.
    if (newBase == 2 || newBase == 8)
    {
        while (num > 0)
        {
            remainder = num % newBase;
            myInts.push(remainder);
            counter++;

            num = num / newBase;
        }

        for (int k = 0; k < counter; k++)
        {
            cout << myInts.top();
            myInts.pop();
        }
        if (newBase == 8)
            cout << " - base 8." << endl;
        else
            cout << " - base 2." << endl;
        counter = 0;//Reset counter.
        remainder = 0;//Reset remainders.
    }

    //If converting to HEX.
    else if (newBase == 16)
    {
        while (num > 0)
        {
            remainder = num % newBase;
            myInts.push(remainder);
            counter++;
            num = num / newBase;
        }

        for (int k = 0; k < counter; k++)
        {
            if (myInts.top() > 9)
            {
                char hexChar = myInts.top() = (myInts.top()-10) + 65;
                cout << (char)myInts.top();
                myInts.pop();
            }
            else
            {
                cout << myInts.top();
                myInts.pop();
            }
        }
        cout << " - base 16." << endl;
        remainder = 0;//Reset remainders.
        counter = 0;//Reset counter.
    }


    return 0;
}
