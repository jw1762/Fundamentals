/* Authors: Jordan Williamson & Samuel Cantrell
 Group #: 19
 Due Date: September 16th, 2014
 Programming Assignment Number: 2
 CS 1428.002 Fall 2014
 Instructor: Husain Gholoom

 */

 #include <iostream>
 using namespace std;

 int main()
 {
    cout << "This program is written by Jordan Williamson & Samuel Cantrell.\n"<<endl;
    cout << "The function of this program is to read from a keyboard a five digit number." <<endl;
    cout << "The program should separate the numbers into its individual digits and"<<endl;
    cout << " displays digits separated from one another by three spaces each.\n"<<endl;
    cout << "Please enter a five digit number of type integer : ";

    string number; //The 5 digit input.
    cin >> number;
    cout << "\n";

    cout << "The output is : ";

    for(int spNumber=0; spNumber < 5; ++spNumber) // A loop to output the first 5 digits of 'number'.
    cout << number[spNumber]<<"   ";
    cout << "\n";

 }
