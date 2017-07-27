/* Authors: Jordan Williamson & Samuel Cantrell
 Group #: 19
 Due Date: October 30th, 2014
 Programming Assignment Number: 8
 CS 1428.002 Fall 2014
 Instructor: Husain Gholoom
 */

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
     cout << "This program is written by Jordan Williamson & Samuel Cantrell\n\n";
     cout << "The function of this program is to find the frequency of each number that has been drawn in the Texas lotto game.\n";
     cout << "The program :\n";
        cout << "\t1.\t Calculates and displays the frequency of drawn numbers in Texas Lotto each year.\n";
        cout << "\t2.\t Calculates and displays the overall frequency of each number that has been drawn since the lotto started.\n";
        cout << "\t3.\t Sorts the frequency numbers in Descending order.\n";
        cout << "\t4.\t Displays the number of valid integers.\n";
        cout << "\t5.\t Displays the number of rejected integers.\n";
        cout << "\t6.\t Displays the total number of integers in the entire file.\n\n";


    ifstream fin;
    int temp;
    int numfail = 0, numpass = 0, numtotal = 0;

    int totalNum[55], tnumindex[55], yearNum[55]; // 54 possible numbers
    for (int zero = 0; zero < 55; zero++)// sets values to zero
    {
        totalNum[zero] = 0;
        tnumindex[zero] = zero+1;
        yearNum[zero] = 0;
    }

    fin.open ("lottofile.txt");


    while (!fin.eof()) // initial parse of the entire file
{
    fin >> temp; // year
    //cout << temp << " ";
    for (int x=0; x<6; x++) // 6 lotto numbers
    {
    fin >> temp;
    numtotal++;
        if (temp >= 1 && temp <= 54)
        {
            totalNum[(temp-1)]++;
            numpass++;
        }
        else
            numfail++;
    //cout << temp << " ";
    }
    cout << endl;
}


    cout << "\nFor each year, the frequency of drawn numbers in the Texas Lotto are as follows :-\n\n";
    for (int numyear = 1980; numyear < 2015; numyear++) // Year nums
{
    fin.clear(); // resets fail state and places the pointer at the top of the file
    fin.seekg(0);
   while (!fin.eof()) // parse of the entire file
{
    fin >> temp; // year
    if (temp == numyear)
    {
    //cout << temp << " ";
    for (int x=0; x<6; x++) // 6 lotto numbers
    {
    fin >> temp;
        if (temp >= 1 && temp <= 54)
        {
            yearNum[(temp-1)]++;
            //cout << temp << " ";
        }
    }
    }
    else
        for (int y=0; y<6; y++) // 6 lotto numbers
                            fin >> temp;
    //cout << endl;
}
    int i=0,j=0,n=1;
    // Static frequency
    do
{
    cout << "Year -> No ";
    for (;i<9*n; i++)
        cout << tnumindex[i] << "\t";
    cout << "|\n";
    cout << numyear << "      ";
    for (;j<9*n; j++)
        cout << yearNum[j] << "\t";
    n++;
    cout << "\n";
}   while (i<54);
    // output for each year
    for (int reset = 0; reset< 54; reset++)// sets values to zero
        yearNum[reset] = 0;
}



    int i=0,j=0,n=1;
    cout << "\nOver All the Data, The Frequency of drawn numbers in the Texas Lotto are   :-\n\n"; // Static frequency
    do
{
    cout << "No  --->  ";
    for (;i<9*n; i++)
        cout << tnumindex[i] << "\t";
    cout << "|\n";
    cout << "Frequency ";
    for (;j<9*n; j++)
        cout << totalNum[j] << "\t";
    n++;
    cout << "\n";
}   while (i<54);
    cout << endl;



    cout << "The MOST frequent Numbers Drawn in the Texas LOTTO Game from Highest to Lowest\n\n";
    bool test = false;
    int temp2 = 0;
    while (test == false)
{
      for(int v=0; v<54; v++)
      {
          for (int u = v; u < 54; u++)
          {
          if((totalNum[v])<(totalNum[u]))
          {
              temp = totalNum[v];
              totalNum[v] = totalNum[u];
              totalNum[u] = temp;
                temp = tnumindex[v];
              tnumindex[v] = tnumindex[u];
              tnumindex[u] = temp;
             // cout << temp << endl;
          }
          }
      }
      temp2 = 0;
        for(int p=0; p<54; p++)
      {
          for(int o = p; o < 54; o++)
          if((totalNum[p])>(totalNum[o]))
              temp2++;
      }
          if (temp2 == 1411)
              test = true;
}
    i=0;j=0;n=1; // Static frequency
    do
{
    cout << "No  --->  ";
    for (;i<9*n; i++)
        cout << tnumindex[i] << "\t";
    cout << "|\n";
    cout << "Frequency ";
    for (;j<9*n; j++)
        cout << totalNum[j] << "\t";
    n++;
    cout << "\n";
}   while (i<54);



    cout << "Number of valid integers read\t:\t " << numpass << endl;
    cout << "Number of rejected integers read:\t " << numfail << endl;
    cout << "Total amount of integers read\t:\t " << numtotal << endl;

    //int year[];
    fin.close();
    return 0;
}
