/****************************************************
File Name: biodataHelp_A00643150.cpp

Author: Jordan Williamson
Date: 1/27/2015
Problem Number: 1
CS 2308 Spring 2015
Instructor: Priebe

A program consisting of two functions to take timestamps and
temperatures from a file and output in a readable format.
*****************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

void timestampConvert(int, string);
double tempConvertTotal(string, int, double &totalTemp);

ifstream inFile;
ofstream outFile;

int main()
{
    inFile.open("biodata.dat");
    outFile.open("results.dat");

    cout << "Reading from file biodata.dat...\n" << endl;

    double dataNums;
    inFile >> dataNums;
//cout <<"dataNums is "<< dataNums << endl;

    double totalTemp = 0;
    double tempAverage = 0;
//cout << "totalTemp is " << totalTemp << endl;
//cout << "tempAverage is " << tempAverage << endl;

    for (int i = 0; i < dataNums; i++)
    {
    string timeStamp;
    inFile >> timeStamp;
//cout << "timeStamp is " << timeStamp << endl << endl;

    string temp;
    inFile >> temp;
//cout << "temp is " << temp << endl<<endl;

    totalTemp = tempConvertTotal(temp, dataNums, totalTemp);
//cout << "totalTemp from tempConvert function is " << totalTemp << endl << endl;

    timestampConvert(dataNums, timeStamp);
//cout << "timestampConvert function is " << x << endl << endl;

    tempAverage = totalTemp / dataNums;
//cout << "tempAverage is " << tempAverage << endl << endl;
    }

    cout << "\nAverage Temperature --- " << tempAverage << "C\n";
    outFile << "\nAverage Temperature --- " << tempAverage << "C\n";
    cout << "\nThe preceding data has been written to 'results.dat'...\n" << endl;

    inFile.close();
    outFile.close();

    cout << "End of program." << endl;
    return 0;
}

void timestampConvert(int dataNums, string timeStamp)
{
    string dateStamp = timeStamp.substr(4,2) + "/" + timeStamp.substr(6,2) + "/" + timeStamp.substr(0,4);
    cout << "recorded on " << dateStamp << " ";
    outFile << "recorded on " << dateStamp << " ";

    string hmStamp = timeStamp.substr(8,2) + ":" + timeStamp.substr(10,2);
    cout << "at "<< hmStamp << endl;
    outFile << "at "<< hmStamp << endl;
}

double tempConvertTotal(string temp, int dataNums, double &totalTemp)
{
    string tempType = temp.substr(0,1);
    string Temperature = temp.substr(1,temp.length());
    double tempNum = atof(Temperature.c_str());
//The conversion for Farenheit to Celsius
    double tempConversion = ((tempNum - 32) * 5) / 9;

    if (tempType == "F")
    {
    cout << setprecision(4) << tempConversion << " C --- ";
    outFile << setprecision(4) << tempConversion << " C --- ";
    }
    else
    {
    outFile << Temperature << " C --- ";
    cout << Temperature << " C --- ";
    }
//Finds the total temperature after converting.
        if (tempType == "F")
        totalTemp = totalTemp + tempConversion;
        else
        totalTemp = totalTemp + tempNum;

    return totalTemp;
}
