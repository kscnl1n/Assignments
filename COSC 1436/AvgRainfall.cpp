/*

Name: Kaylee Scanlin
Date: 09/14/2023
Description: The following program is meant to
Write a program that calculates the average rainfall for three months.
The program should ask the user to enter the name of each month,
such as June or July, and the amount of rain (in inches) that fell each
month. The program should display a message similar to the following:
The average rainfall for June, July, and August is 6.72 inches.


I am going to implement a file stream object to practice files.
*/




#include <iostream>
#include <string>
#include <fstream> // for file manipulators
using namespace std;
int main()
{

    ofstream AvgRain;

    //1. Name variables
    AvgRain.open("AverageRainfall.txt");
    string month1, month2, month3;
    double rain1, rain2, rain3;

    //2. Prompt user for input
    cout << "Enter the three months: ";

    //3. Take user input
    cin >> month1 >> month2 >> month3;

    //2. Prompt user for input
    cout << "Enter the three average rainfall measurements for the previous three months, in the same order, in inches: ";

    //3. Take user input
    cin >> rain1 >> rain2 >> rain3;

    //4. Display output

    AvgRain << "Average rainfall for months " << month1 << ", " << month2 << ", and " << month3 << " is " << fixed << showpoint << setprecision(2) << ((rain1 + rain2 + rain3)/3) << "in";

    AvgRain.close();

    return 0;
}
