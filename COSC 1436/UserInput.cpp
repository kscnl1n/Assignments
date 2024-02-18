/*
Name: Kaylee Scanlin
Course: COSC 1436
Due date: 09/07/2023
Description:

The purpose of the following program is to calculate and report the average temperature in july would be for 3
separate cities--chosen by the user--if their temperatures raised by 2%.
*/


#include <iostream>

// Including the iomanip header file for setprecision function.
#include <iomanip>

//Including string header file to store city names.
#include <string>

using namespace std;
int main()
{
    //1. Naming variables
    // The following strings are for the cities, and the doubles are for temperatures before and after the temperature increase.

    string city1, city2, city3;

    double temp1, temp2, temp3;

    double postTemp1, postTemp2, postTemp3;

    //2a. Getting user input

    cout << "Enter the names of the three cities: ";

    //3a. Storing input into variables
    //We will use the getline function so whitespace isn't ignored

    getline(cin, city1);

    getline(cin, city2);

    getline(cin, city3);

    //2b. Getting user input

    cout << "Enter the temperatures of each city respectively, in the order of " << city1 << ", " << city2 << ", and " << city3;

    //3a. Storing input into variables

    cin >> temp1 >> temp2 >> temp3;

    //4. Internal logic/calculations

    postTemp1 = temp1 * 1.02;

    postTemp2 = temp2 * 1.02;

    postTemp3 = temp3 * 1.02;

    //5. Displaying program output

    cout << "The average temperatures after a 2% average temperature increase for " << city1 << ", " << city2 << ", and " << city3 << " would be " <<
    postTemp1 << " degrees Fahrenheit, " << postTemp2 << " degrees Fahrenheit, and " << postTemp3 << " degrees Fahrenheit. " << endl;


return 0;
}
