/*

Name: Kaylee Scanlin
Date: 09/14/2023
Description: The following program is meant to
write a program that asks the user for the number of males and the
number of females registered in a class. The program should display
the percentage of males and females in the class.
Hint: Suppose there are 8 males and 12 females in a class. There are
20 students in the class. The percentage of males can be calculated as
8 ÷ 20 = 0.4, or 40 percent. The percentage of females can be
calculated as 12 ÷ 20 = 0.6, or 60 percent.
*/




#include <iostream>
#include <string>
#include <iomanip>
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
