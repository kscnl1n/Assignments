/* Kaylee Scanlin
* August 31st, 2023
* COSC 1436
* Description: Chapter 2 Practice
  The purpose of the following program is to calculate the tax and tip a patron will have to pay based upon a specific meal charge.
  The tax should be %6.75 of the meal cost.
  The tip should be %20 of the total, after adding the tax.
*/

#include <iostream>

double score;

using namespace std;

int main()

{

    //0. Constants
    //Numbers/variables/any values that do not change throughout the program. Remember to put all constants in uppercase!
    double const TAX_RATE = 0.0675;


    //1. Variables
    double mealCost = 88.67;
    double taxRate = 00.00;
    // double mealCost = 00.00;
    double taxAmount = 00.20;
    double tipAmount = 00.00;
    double totalBill = 00.00;

    //2. Taking user input

    //3. Storing input

    //4. Calculations and logic
    taxAmount = TAX_RATE * mealCost;
    tipAmount = taxRate * (taxAmount + mealCost);
    totalBill = mealCost + taxAmount + tipAmount;


    //5. Display
    // It's always a good idea to display the input as well just to cover any potential mistakes on the customer's end!
    cout << "Meal Cost: " << mealCost << endl;
    cout << "Tax Amount: " << taxAmount << endl;
    cout << "Tip Amount: " << tipAmount << endl;
    cout << "Total Bill: " << totalBill << endl;


    //Although in the early days of C++, programmers needed a return 0 at the end of their main function
    //to terminate it, today C++ automatically terminated your main function for you.

    return 0;

}
