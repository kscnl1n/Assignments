/*

Name: Kaylee Scanlin
Course: COSC 1436
Due date: 09/07/2023
Description: If 1 acre of land is equivalent to 43,560 ft^2. Write a program that calculates the number of acres in a tract of land with
391, 876 ft^2.

*/


#include <iostream>

// Including the iomanip header file for setprecision function.
#include <iomanip>
using namespace std;
int main()
{
    //0. Defining constants
    int const SQ_FT_IN_ACRE = 43560;

    //1. Defining variables

    // The following is for the number of square feet in a tract of land owned by the user.
    double sqFtOwned;

    // The following is for the number of acres in the tract of land.
    double numberOfAcres;

    //2. Talk to the user to get input
    cout << "Enter the amount of square feet in your tract of land: ";

    //3. Store input into variables
    cin >> sqFtOwned;

    //4. Internal logic/calculations
    numberOfAcres = sqFtOwned / SQ_FT_IN_ACRE;

    //5. Display output (I chose to display it to the second decimal point)

    cout << "You own " << fixed << setprecision(2) << sqFtOwned << " square feet of land, which is equal to " << fixed << showpoint << setprecision(2) << numberOfAcres << " in acres." << endl;


return 0;
}
