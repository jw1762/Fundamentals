/*************************************************************
File Name: checker_A00643150.cpp
Author: Jordan Williamson
Date: 5/1/2015
Problem Number: 8
CS 2308 Spring 2015
Instructor: Priebe, Roger

A basic program which takes in equations and then determines
whether or not there are an appropriate number of parenthesis
and brackets.
***************************************************************/
#include <iostream>
#include <fstream>
#include <stack>
#include <stdlib.h>

using namespace std;

bool pairs(char opening, char closing)
{
	if(opening == '(' && closing == ')')
        return true;
	else if(opening == '[' && closing == ']')
        return true;
    else
        return false;
}

bool balanceCheck(string exp)
{
    stack<char> mySymbols;

    for (int i = 0; i < exp.length(); i++)
    {
        if(exp[i] == '(' || exp[i] == '[' )
        {
            mySymbols.push(exp[i]);
        }

        else if (exp[i] == ')' || exp[i] == ']')
        {
            if(mySymbols.empty() || !pairs(mySymbols.top(), exp[i]))
                return false;
            else
                mySymbols.pop();
        }

    }
    return mySymbols.empty()? true:false;
}

int main(int argc, char *argv[])
{
    char buffer[80];

    ifstream inFile;
    inFile.open(argv[1]);
    inFile.getline(buffer, 80);
    string s;

    if (!argv[1])
    {
        cout << "Missing argument from cmd prompt. Ending program..." << endl;
        return 0;
    }

    while(!inFile.eof())
    {
        s = buffer;

        if(balanceCheck(s) == true)
        {
            cout << s << " is valid." << endl;
        }

        else if(balanceCheck(s) == false)
        {
            cout << s << " is invalid." << endl;
        }
        inFile.getline(buffer, 80);

        //Kept skipping final line.
        //Final line will now be read.
        if(inFile.eof())
        {
            s = buffer;
            if(balanceCheck(s) == true)
            {
                cout << s << " is valid." << endl;
            }
            else if(balanceCheck(s) == false)
            {
                cout << s << " is invalid." << endl;
            }
        }
    }
    return 0;
}
