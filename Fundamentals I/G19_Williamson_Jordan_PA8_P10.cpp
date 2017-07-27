/* Authors: Jordan Williamson & Samuel Cantrell
 Group #: 19
 Due Date: December 4th, 2014
 Programming Assignment Number: 10
 CS 1428.002 Fall 2014
 Instructor: Husain Gholoom

 The purpose of this program is to generate a report after reading data from a file
 and displaying any relevant info such as highest salesperson, highest sales quarter, and more.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct salesPersonRecord
{
    int SalesPersonID; //ID for each SalesPerson
    double saleByQuarter[4]; //Array to store total sales for each QT.
    double totalSale; // salesperson yearly sales amount.
};

int getData(salesPersonRecord []);//Reads data from sales.txt and stores info into struct array.
int salesByQT(salesPersonRecord [], double[]);//Function that finds totalSales for each QT.
void totalSales(salesPersonRecord []);//Function finds each persons yearly sale amount for 4 QTs and stores back value in Struct Array.
void printReport(salesPersonRecord [], double[]); // Prints annual report in proper format.
void maxSaleP(salesPersonRecord []);//Prints name of person who produces max sales amount.
void maxSaleQT(salesPersonRecord [], double[]);//Prints the QT in which max sales were made.

int main()
{
    double QT[4];
    int quit = 1;
    salesPersonRecord Sales[6];
    quit = getData(Sales);
    if (quit == 0)
    {
        return 0;
    }
    salesByQT(Sales, QT);
    totalSales(Sales);
    printReport(Sales, QT);
    maxSaleP(Sales);
    maxSaleQT(Sales, QT);
    cout << "\n\nThis report is prepared by Jordan Williamson and Samuel Cantrell.\n";
    cout << "District number : 19\n\n";
    cout << "Date : 12-4-2014\n";
    return 0;
}

int getData(salesPersonRecord Sales[])
{
    fstream fin;
    fin.open("sales.txt");

    if (!fin)
    {
        cout << "Sorry! No sales.txt is available to read from. Program Terminating...\n";
        return 0;
    }

    for (int x = 0; x < 6; x++)
    {
    fin >> Sales[x].SalesPersonID;

    for (int y=0; y<4; y++)
    {
        fin >>Sales[x].saleByQuarter[y];
    }
    }
    fin.close();
}

int salesByQT(salesPersonRecord Sales[], double QT[])
{
    for (int x = 0; x < 6; x++)
    {
        QT[0] += Sales[x].saleByQuarter[0];
        QT[1] += Sales[x].saleByQuarter[1];
        QT[2] += Sales[x].saleByQuarter[2];
        QT[3] += Sales[x].saleByQuarter[3];
    }
}

void totalSales(salesPersonRecord Sales[])
{
    for (int i=0;i<6;i++)
        {
        Sales[i].totalSale = 0;
        }

    for(int i = 0;i<6; i++)
        {
        for (int x = 0; x < 4;x++)
        {
        Sales[i].totalSale += Sales[i].saleByQuarter[x];
        }
        }
}

void printReport(salesPersonRecord Sales[], double QT[])
{
        cout << "\tBubba's Chemical Supply Company\n";
        cout << "-----------Annual Sales Report - 2013-----------\n\n";
        cout << "ID\t  QT1\t  QT2\t  QT3\t  QT4\t  Total\n";
        cout << "_________________________________________________\n";

        for (int x = 0; x < 6; x++)
        {
            cout << Sales[x].SalesPersonID;
            for (int y=0; y<4; y++)
            {
                cout << "\t" << fixed << setprecision(2) << Sales[x].saleByQuarter[y];
            }
            cout << "\t" << setprecision(2) << Sales[x].totalSale;
            cout << "\n";
        }
        cout << "\nTotal";
        for (int x = 0; x < 3;x++)
        cout << "\t" << QT[x];
        cout << " " << QT[3];
}

void maxSaleP(salesPersonRecord Sales[])
{
    double maxSale = Sales[0].totalSale;
    double maxP = Sales[0].SalesPersonID;
    for (int u = 0; u < 6; u++)
    {
        for (int t = 0; t < 4; t++)
        {
        if (Sales[u].totalSale > maxSale)
        {
            maxSale = Sales[u].totalSale;
            maxP = Sales[u].SalesPersonID;
        }
        }
    }
    cout << "\n\nMax sale by Salesperson ID: " << static_cast<int>(maxP)<<" ,";
    cout << "\tAmount = $" << maxSale << "\n\n";
}

void maxSaleQT(salesPersonRecord Sales[], double QT[])
{
    double maxQ = 0;
    int maxQTS = 0;
    for (int x = 0; x < 6; x++)
    {
        for (int y = 0; y < 4; y++)
        {
        if (QT[x] > maxQ)
            maxQ = QT[x];
            maxQTS = y;
        }
    }
    cout << "Max sale by quarter: Quarter = " << maxQTS<<" ,";//static_cast<int>(maxQTS);
    cout << "\tAmount = $" << maxQ;
}
