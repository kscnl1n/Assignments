/*
Name: Kaylee Scanlin

Course: COSC 1436

Due date: 09/08/2023

Assignment Description: The purpose of the following program is to utilize what we learned in Chapter 2 to create a program
that will take as input the amount of a purchase in USD, and return the state (5%) and county (2.5%) sales tax, the total sales tax,
and the total and original price.

Notes: We did this assignment together in class, but I seem to have lost the file, so I re-did it on my own to the best of
my abilities.

*/

//Include the cin/cout libraries.

#include <iostream>

//Include the fixed and setprecision() stream manipulators.

#include <iomanip>

using namespace std;

int main()
{

    //1. Defining variables

    // Defining constant values.

    // The advantage of using constants is that they aren't changed throughout the duration of the program--if you

    // have a constant defined as "TAX_RATE", for example, if the tax rate required by the program changes, instead of

    // going back and changing every single value serving as the tax rate in the program, the programmer can change the value

    // of the TAX_RATE variable to the same effect.

    // You can tell these variables are constants as opposed to the stateTax and countyTax because they are in all-caps.

    const double STATE_TAX = 0.05;

    const double COUNTY_TAX = 0.025;

    // Defining mutable variables to store the purchase amount, the amount of state tax, the amount of county tax, and the total sales tax

    // (state + county tax) respectively.

    double purchaseAmount, stateTax, countyTax, salesTax;



    //2. Reading user input

    // Prompting the user for input using the cout (console out) function.

    cout << "Enter the amount of your purchase: ";

    // Reading the user input into the purchaseAmount variable.

    cin >> purchaseAmount;



    //3. Performing calculations/logic "under the hood" of the program

    // Finding the amount of state tax, county tax, and sales tax.


    stateTax = (purchaseAmount * STATE_TAX);

    countyTax = (purchaseAmount * COUNTY_TAX);

    salesTax = stateTax + countyTax;



    //4. Displaying the output.

    // Here, several stream manipulators are used to format the output exactly how we want it.

    // I couldn't figure out how to display the output to 2 decimal places using what we learned in chapter 2 alone,

    // so I used some commands from chapter 3:

    // 'Showpoint' forces the value to display to the 6th decimal point.

    // 'Setprecision()' is a function that truncates these decimal points to a certain decimal place- in this case, the 2nd.

    // The 'fixed' stream manipulator prevents the number from being rounded off to a certain decimal point.

    cout << "Purchase Amount: $" << fixed << showpoint << setprecision(2) << purchaseAmount << endl;

    cout << fixed << setprecision(2) << "State Tax: $" << stateTax << endl;

    cout << fixed << setprecision(2) << "County Tax: $" << countyTax << endl;

    cout << fixed << setprecision(2) << "Total Tax: $" << salesTax << endl;

    cout << fixed << setprecision(2) << "Sale Total: $" << (purchaseAmount + salesTax) << endl;



    // Return 0 to let the program know this is the end of our function.

    return 0;
}
