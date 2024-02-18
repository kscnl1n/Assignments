/* Name: Kaylee Scanlin
Date 09/12/2023
Course: COSC 1436
Section: 2001

Description: The purpose of the following program is to calculate the amount of money a single
employee makes in a year.
Assume the employee gets paid every 2 weeks and earns $2,200 each pay period. This employee would be paid 26 times in the span of a year.
Define the following variables in the program:

payAmount - This variable will hold the amount of pay the employee earns each pay period.
Initialize the variable with 2200.0

payPeriods - This variable will hold the number of pay periods in a year. Initialize the variable
with 26.

annualPay - This variable will hold the employee’s total annual pay, which will be calculated

The real purpose of this program, however, is to determine what the variable types should be based upon inference.
Having to make educated guesses as to what data type the variable will be is something that occurs a lot within industry.

*/

#include <iostream>
#include <iomanip> //For setprecision
using namespace std;
int main()
{

    //1. Create variables

    double payAmount = 2200.0;

    int payPeriods = 26;

    //2. Talk to user - skip

    //3. Store input - skip

    //4. Calculations/Logic

    double annualPay = payAmount * payPeriods;

    //5. Display output

    cout << "The employee earns $" << fixed << showpoint << setprecision(2) << annualPay << "in a year." << endl;





    return 0;
}

