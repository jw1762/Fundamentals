/* Authors: Jordan Williamson & Samuel Cantrell
 Group #: 19
 Due Date: October 14th, 2014
 Programming Assignment Number: 7
 CS 1428.002 Fall 2014
 Instructor: Husain Gholoom
 */

 #include <iostream>
 using namespace std;

 int main()
 {
     cout << "This program is written by Jordan Williamson & Samuel Cantrell\n\n";
     cout << "The function of this program is, given 2 positive numbers, the program will display the following:\n\n";
     cout << "\t1. All even numbers between firstNum and secondNum.\n";
     cout << "\t2. All odd numbers between firstNum and secondNum.\n";
     cout << "\t3. Sum of all even numbers between firstNum and secondNum.\n";
     cout << "\t4. Sum of all odd numbers between firstNum and secondNum.\n";
     cout << "\t5. All prime numbers between firstNum and secondNum\n";
     cout << "\t6. The numbers and their squares between firstNum and secondNum.\n\n";

     int firstNum, secondNum;
     cout << "Enter the first number: ";
     cin >> firstNum;
     cout << "Enter the second number: ";
     cin >> secondNum;
     if(firstNum <= 0 || secondNum <= 0) //Checks if negative number.
         {
             cout << "Error: - Invalid number: Numbers must be positive.";
             return 0;
         }

     if(firstNum > secondNum) // Checks that the first number is smaller than the second.
     {
         cout << "Error: The first number must be < second number.";
     }
     else
     cout << "You entered: " << firstNum << " and " << secondNum << "\n\n";
     cout << "\n\t1. All even numbers: ";

     for (int x = 1; x < secondNum; x++)//Loops until reaching the larger number, then outputs even numbers (no remainders).
     {
         if(x%2==0 && x != secondNum - 2)
         {
             cout << x << ", ";
         }else if (x % 2 == 0)
            cout << x;
     }

     cout << "\n\t2. All odd numbers: ";


     for (int x = 0; x <= secondNum; x++) //Loops until largest number, then outputs all odds (remainders).
     {
         if(x % 2 != 0 && x != 1 && x != secondNum - 1)
         {
            cout << x << ", ";
         }else if (x % 2 != 0 && x != 1)
         cout << x;
    }

     cout << "\n\t3. Sum of all even numbers: ";
     int evenSum = 0;

    for (int x = 1; x < secondNum; x++) //Adds together all the even numbers and outputs.
    {
        if(x % 2 == 0)
        evenSum = x + evenSum;
    }
    cout << evenSum;

    cout << "\n\t4. Sum of all odd numbers: ";
    int oddSum = 0;
    for (int x = 0; x <= secondNum; x++)//Adds together all odd numbers and outputs.
    {
        if (x % 2 != 0 && x != 1)
            oddSum = x + oddSum;
    }
    cout << oddSum;
    cout << "\n\t5. All prime numbers: ";

    int pCount1 = 0;
    int pCount2 = 0;
    int prime = 1;

    for(int test = firstNum + 1; test < secondNum; test++)//Finds all prime numbers and counts how many there are
    {
    prime = 1;

    for(int i = 2; i < test; i++)
        if(test % i == 0)
    {
        prime = 0;
        break;
    }
        if (prime == 1)
            pCount1++;
    }

    for(int x = firstNum + 1; x < secondNum; x++)//Finds all prime numbers and outputs.
    {
    prime = 1;

    for(int i = 2; i < x; i++)

        if(x % i == 0)
    {
        prime = 0;
        break;
    }
    if (prime == 1)
         pCount2++;

    if((prime == 1) && (pCount2 < pCount1))
        cout << x << ", ";
    else if (prime == 1)
        cout << x;
    }

    cout << "\n\t6. Number\tSquare\n\n";
    for (int x = firstNum+1; x < secondNum; x++)
    {

        if(x != 1)
            cout << "\t\t" << x;
            cout << "\t" << x*x << "\n\n";
    }


     }
