/* Authors: Jordan Williamson & Samuel Cantrell
 Group #: 19
 Due Date: September 16th, 2014
 Programming Assignment Number: 3
 CS 1428.002 Fall 2014
 Instructor: Husain Gholoom

 The purpose of this program is to receive an age, and output the months, days,
 hours and seconds you have been alive.
 */
#include <iostream>
using namespace std;

int age;
int months = 12;
double days = 365.25;
double hours = 24;
double seconds = 60*60*hours*days;

int main()
{
    cout << "This program is written by Jordan Williamson & Samuel Cantrell\n"<<endl;
    cout << "The function of this program is to prompt the user to input an integer value\n";
    cout << "that represents a persons age. The program then calculates and displays\n";
    cout << "statistics about the persons age.\n"<< endl;
    cout << "Enter Your Age : ";
    cin >> age;
    cout << "You Entered : " << age <<" \n"<< endl;
    cout << "You are " << months * age << " months and " << age * days << " days old."<<endl;
    cout << "You are approximately " << age * hours * days << " hours old" << endl;
    cout << "You are approximately " << fixed << age * seconds << " seconds old"<<endl;

}
