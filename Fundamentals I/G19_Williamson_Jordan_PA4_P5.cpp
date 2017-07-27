/* Authors: Jordan Williamson & Samuel Cantrell
 Group #: 19
 Due Date: October 2nd, 2014
 Programming Assignment Number: 5
 CS 1428.002 Fall 2014
 Instructor: Husain Gholoom
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    cout << "This program is Written By Jordan Williamson & Samuel Cantrell.\n\n";
    cout << "The function of this program is to display the number of reward points a customer earns each month.\n\n";
    cout << "Enter S for Standard Membership Type or\n Enter P for Premium Membership Type or\n Enter G for Gold Membership Type : ";
    float totalPurchase;
    char memberType;
    cin >> memberType;


    //Checks if there is an invalid character entered and rejects it if so.
    if (memberType != 'g' && memberType != 'G' && memberType != 's' && memberType != 'S' && memberType != 'p' && memberType != 'P'){
        cout <<"\n"<< memberType << " is not valid!\n";
    }
    //Otherwise, continues the program.
    else if (memberType == 'g' || memberType == 'G' || memberType == 's' || memberType == 'S' || memberType == 'p' || memberType == 'P'){
    cout << "\nEnter Total Monthly Purchase : ";

    cin >> totalPurchase;
    }

    float rewardPoints;

    if (memberType == 'S' || memberType == 's'){
        if (totalPurchase < 75){
        rewardPoints = totalPurchase * .05;
        cout << "\nNumber of Reward Points Earned : " << setprecision(3) << fixed << rewardPoints << "\n";
        }
        else if (totalPurchase >= 75 && totalPurchase <= 149.99){
            rewardPoints = totalPurchase * .075;
            cout << "\nNumber of Reward Points Earned : " << setprecision(3) << fixed << rewardPoints << "\n";
            }
            else if (totalPurchase >= 150){
                rewardPoints = totalPurchase * .10;
                cout << "\nNumber of Reward Points Earned : " << setprecision(3) << fixed << rewardPoints << "\n";
                }
    }

    if (memberType == 'P' || memberType == 'p'){
        if (totalPurchase < 150){
        rewardPoints = totalPurchase * .06;
        cout << "\nNumber of Reward Points Earned : " << setprecision(3) << fixed << rewardPoints << "\n";
        }
        else if (totalPurchase >= 150){
            rewardPoints = totalPurchase * .13;
            cout << "\nNumber of Reward Points Earned : " << setprecision(3) << fixed << rewardPoints << "\n";
            }
    }

    if (memberType == 'G' || memberType == 'g'){
        if (totalPurchase < 200){
        rewardPoints = totalPurchase * .04;
        cout << "\nNumber of Reward Points Earned : " << setprecision(3) << fixed << rewardPoints << "\n";
        }
        else if (totalPurchase >= 200){
            rewardPoints = totalPurchase * .15;
            cout << "\nNumber of Reward Points Earned : " << setprecision(3) << fixed << rewardPoints << "\n";
            }
    }
return 0;

}

