/* Authors: Jordan Williamson & Samuel Cantrell
 Group #: 19
 Due Date: November 13th, 2014
 Programming Assignment Number: 9
 CS 1428.002 Fall 2014
 Instructor: Husain Gholoom
 */

#include <cctype>
#include <string>
#include <iostream>
using namespace std;


const int SIZE = 5;
void populate(char numbers[SIZE]);
void arrayDisplay(char numbers[SIZE]);
void capitals(char numbers[SIZE]);
void smallL(char numbers[SIZE]);
void digits(char numbers[SIZE]);
int specialS(char numbers[SIZE]);
void arrayR(char numbers[SIZE]);
void smallCap(char numbers[SIZE]);
int tryAnother();


int main()
{
    char numbers[SIZE];

    populate(numbers);
    cout << "\n\n";

    capitals(numbers);
    smallL(numbers);
    digits(numbers);
    specialS(numbers);

    cout << "\nThe array in reverse order: ";
    arrayR(numbers);
    cout << "\n\n";

    cout << "The array after converting capital to small and vice versa: ";
    smallCap(numbers);
    cout << "\n";

    cout << "\nWould you like to check another array\n" << "Enter Y or y FOR YES\nOR\nN or n FOR NO ------->\t" ;
    tryAnother();
return 0;
}

//1. Allow the user to populate the array by entering 5 characters from the
//key board.
void populate(char numbers[SIZE])
{
    string input;

    cout << "Enter any 5 Characters, Digits or Special Symbols :\t";
    cin >> input;

    int test = input.length();
    if(test>5)
    {
       cout << "\nNo more than 5!\n"; //error message?
    }
    else
    {
     for(int p=0; p<SIZE; p++)
        numbers[p] = input[p];//place the string into the array
    cout << "\n";
    }
    cout << "The array contains the following: ";
    arrayDisplay(numbers);
}

//2. Display the entire array.
void arrayDisplay(char numbers[SIZE])
{
    for(int counter = 0; counter < SIZE; ++counter)
    {
    cout << numbers[counter] << " ";
    }
}

//3. Display all capital letters or none in the array.
void capitals(char numbers[SIZE])
{
    int test = 0;
    for(int counter = 0; counter < SIZE; ++counter)
    {
    if (numbers[counter] >= 'A' && numbers[counter] <= 'Z'){
    cout << numbers[counter] << " is a Capital Letter!\n";
    test = 1;}
    }
    if (test == 0)
        cout << "There are No Capital Letters in the Array\n";
}

//4. Display all small characters or none in the array.
void smallL(char numbers[SIZE])
{
    int test = 0;
    for(int counter = 0; counter < SIZE; ++counter)
    {
    if (numbers[counter] >= 'a' && numbers[counter] <= 'z'){
    cout << numbers[counter] << " is a Small Letter!\n";
    test = 1;}
    }
    if (test == 0)
        cout << "There are No Small Letters in this Array\n";
}

//5. Display all digits or none in the array.
void digits(char numbers[SIZE])
{
    int test = 0;
    for(int counter = 0; counter < SIZE; ++counter)
    {
    if (numbers[counter] >= 48 && numbers[counter] <= 57)
    {
    cout << numbers[counter] << " is a Digit!\n";
    test = 1;
    }
    }
    if (test == 0)
        cout << "There are No Digits in this Array\n";
}

//6. Display all speical symbols or none in the array.
int specialS(char numbers[SIZE])
{
    int test = 0;
    for(int counter = 0; counter < SIZE; ++counter)
    {
    if (numbers[counter] >= 33 && numbers[counter] <= 47)
    {
    cout << numbers[counter] << " is a Special Symbol!\n";
    test = 1;
    }
    if (numbers[counter] >= 58 && numbers[counter] <=  64)
    {
    cout << numbers[counter] << " is a Special Symbol!\n";
    test = 1;
    }
    if (numbers[counter] >= 91 && numbers[counter] <= 96)
    {
    cout << numbers[counter] << " is a Special Symbol!\n";
    test = 1;
    }
    if (numbers[counter] >= 123 && numbers[counter] <= 126)
    {
    cout << numbers[counter] << " is a Special Symbol!\n";
    test = 1;
    }
    }
    if (test == 0)
        cout << "There are No Special Symbols in this Array\n";
}

//7. Reverse the order of the element of the array then display the array.
void arrayR(char numbers[SIZE])
{
    char temp[5];

    for (int x = 0; (x < SIZE); x++)
    {
        temp[SIZE-1-x] = numbers[x];
    }
    for (int y = 0;y < (SIZE);y++)
    {
        numbers[y] = temp[y];
    }
    arrayDisplay(numbers);
}

//8. Convert all small letters to capital letters and vice versa , then
//disaply the array.
void smallCap(char numbers[SIZE])
{
    int temp;
    char pass;
    for(int counter = 0; counter < SIZE; ++counter)
    {
    if (numbers[counter] >= 'A' && numbers[counter] <= 'Z'){ // If a Capital Letter
     temp = numbers[counter]; temp+=32;
     pass = temp;
     numbers[counter] = pass;}

    else if (numbers[counter] >= 'a' && numbers[counter] <= 'z'){ // If a Small Letter
     temp = numbers[counter]; temp-=32;
     pass = temp;
     numbers[counter] = pass;}
    }
    arrayDisplay(numbers);
}
//Asks if you want another array.
int tryAnother()
{
    char repeat;
    cin >> repeat;

  switch (repeat)
  {
  case 'y':
  case 'Y':
      main();
      break;
  case 'N':
  case 'n':
     cout << "\nProgram is Terminated\n";
     return 0;
     break;
  default:{
    cout << "Invalid Character, Enter Y, or y, or N, or n\t--- > ";tryAnother();}
  }
}
