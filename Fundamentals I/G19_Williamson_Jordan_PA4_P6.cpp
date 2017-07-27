/* Authors: Jordan Williamson & Samuel Cantrell
 Group #: 19
 Due Date: October 2nd, 2014
 Programming Assignment Number: 6
 CS 1428.002 Fall 2014
 Instructor: Husain Gholoom
 */

 #include <iostream>
 #include <iomanip>

 using namespace std;

 int main()
 {

     cout << "This program is written by Jordan Williamson & Samuel Cantrell\n\n";
     cout << "The function of this program is to display the number of daily calories needed to maintain your current weight.";
     cout << " The number of calories is based on your gender, activity level and weight.\n\n";

     char gender;
     char actLevel;
     int weight;
     int caloriesN;

     cout << "Enter Gender : ";
     cin >> gender;

     switch(gender)
     {
     case 'f':
     case 'F':
            cout << "Enter your activity level : ";
            cin >> actLevel;
            cout << "\n";

            switch(actLevel)
            {
            case 'a':
            case 'A':
                    cout << "Enter your weight : ";
                    cin >> weight;
                    cout << "\n";
                    caloriesN = 12 * weight;
                    cout << "Number of calories needed to maintain current weight : " << caloriesN;
                    break;
            case 'i':
            case 'I':
                    cout << "Enter your weight : ";
                    cin >> weight;
                    caloriesN = 10 * weight;
                    cout << "Number of calories needed to maintain current weight : " << caloriesN;
                    break;
            default:
            cout << actLevel << " is an invalid activity level! Use I or A.";
            break;
            }
        break;

        case 'm':
        case 'M':
            cout << "Enter your activity level : ";
            cin >> actLevel;
            cout << "\n";

            switch(actLevel)
            {
            case 'a':
            case 'A':
                    cout << "Enter your weight : ";
                    cin >> weight;
                    caloriesN = 15 * weight;
                    cout << "Number of calories needed to maintain current weight : " << caloriesN;
                    break;
            case 'i':
            case 'I':
                    cout << "Enter your weight : ";
                    cin >> weight;
                    caloriesN = 13 * weight;
                    cout << "Number of calories needed to maintain current weight : " << caloriesN;
                    break;
            default:
            cout << actLevel << " is an invalid activity level! Use I or A only.";
            break;
            }
        break;

    default:
    cout << "Invalid gender!";
    break;
    }

 }
