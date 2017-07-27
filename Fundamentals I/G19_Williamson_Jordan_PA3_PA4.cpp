/* Authors: Jordan Williamson & Samuel Cantrell
 Group #: 19
 Due Date: September 23rd, 2014
 Programming Assignment Number: 4
 CS 1428.002 Fall 2014
 Instructor: Husain Gholoom
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double taxRate;
int fuelCost;
double houseCost;

int main()
{
    fstream fin;
    ofstream fout;
    fout.open("output.txt");
    fin.open("input.txt");

// Header for the Output file.
    fout << "Initial House Cost\tAnnual Fuel Cost\tTax Rate\tTotal Cost After 5 Years\n\n";

// Reads the first 3 numbers, calculates, and outputs to fout.
    fin >> houseCost >> fuelCost >> taxRate;
    const double totalCost1 = (fuelCost*5.0)+((taxRate*houseCost)*5.0)+houseCost;
    fout << "$" << fixed << setprecision(2) << houseCost << "\t\t$" << fuelCost << "\t\t\t" << fixed << setprecision(3) << taxRate << "\t\t$" << setprecision(2)<< totalCost1<<endl;

// Outputs console information before variables change.
    cout << "This program is written by Jordan Williamson\n\n";
    cout << "Given the initial cost of the house, estimated fuel cost, and the annual\ntax rate, the function of this program is to determine the total cost after a\nfive year period for a house.\n\n";
    cout << "Initial House Cost\tAnnual Fuel Cost\tTax Rate\tTotal Cost\n\n";
    cout << "$" << fixed << setprecision(2) << houseCost << "\t\t$" << fuelCost << "\t\t\t" << fixed << setprecision(3) << taxRate << "\t\t$" << setprecision(2)<< totalCost1<<endl;

// Reads the next 3 numbers, calculates, and outputs to fout. Then displays new a new line on console.
    fin >> houseCost >> fuelCost >> taxRate;
    const double totalCost2 = (fuelCost*5.0)+((taxRate*houseCost)*5.0)+houseCost;
    fout << "$" << houseCost << "\t\t$" << fuelCost << "\t\t\t" << fixed << setprecision(3) << taxRate << "\t\t$" << setprecision(2)<< totalCost2<<endl;
    cout << "$" << houseCost << "\t\t$" << fuelCost << "\t\t\t" << fixed << setprecision(3) << taxRate << "\t\t$" << setprecision(2)<< totalCost2<<endl;

    fin.close();
    fout.close();

// NOTE: The format of output.txt IS CORRECT in Notepad, but not if it is opened in CodeBlocks. Couldn't figure out why.


return 0;
}
