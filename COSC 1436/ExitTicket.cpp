/*
Name: Kaylee Scanlin
Course: COSC 1436
Due date: 09/07/2023
Description: Write a program that stores the integers from the user in
variables and calculates and displays their product in a variable named prod.

*/


#include <iostream>

using namespace std;
int main()
{
    //1. Defining variables

    double num1 = 0, num2 = 0, prod = 0;

    //2a Prompting user for input

    cout << "Please enter the first number: ";

    //3a Storing user input

    cin >> num1;

    //2b Prompting user for input

    cout << endl << "Please enter the second number: ";

    //3b Storing user input

    cin >> num2;

    //4. Calculations/internal logic

    prod = num1 * num2;

    //5. Displaying output

    cout << endl << "The product of " << num1 << " and " << num2 << " is " << prod << "." << endl;


return 0;
}
