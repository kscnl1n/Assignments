/*
Name: Kaylee Scanlin

Course: COSC 1436, Section 2001

Due Date: September 26, 2023

Assignment Description: Write a program that asks the user for the number of brown m&ms, blue m&ms, yellow m&ms, green m&ms and orange m&ms.
The program should display the percentage of each m&m color.

NOTES: I am so sorry this is late prof I didn't know I had to turn this in on D2L if I was attending virtually.

*/

#include <iostream>
using namespace std;
int main()
{

    // 1. DEFINING VARIABLES

    // Double value for the number of m&ms of each color, as well as the total # of m&ms in the bag.
    // **Although they will be integer values, we can't perform calculations on integers because they
    // truncate and do not round.

    double brown, blue, yellow, green, orange, total;

    //2. TALK TO USER & 3. STORE USER INPUT

    cout << "Enter the amount of Brown m&ms: ";

    cin >> brown;

    cout << "Enter the amount of Blue m&ms: ";

    cin >> blue;

    cout << "Enter the amount of Yellow m&ms: ";

    cin >> yellow;

    cout << "Enter the amount of Green m&ms: ";

    cin >> green;

    cout << "Enter the amount of Orange m&ms: ";

    cin >> orange;

    //4. INTERNAL CALCULATIONS

    total = brown + blue + yellow + green + orange;

    //5. DISPLAY DATA

    cout << endl;

    cout << "The percentage of Brown M&Ms is: %" << (brown / total)*100 << endl;

    cout << "The percentage of Blue M&Ms is: %" << (blue / total)*100 << endl;

    cout << "The percentage of Yellow M&Ms is: %" << (yellow / total)*100 << endl;

    cout << "The percentage of Green M&Ms is: %" << (green / total)*100 << endl;

    cout << "The percentage of Orange M&Ms is: %" << (orange / total)*100 << endl;

    return 0;

}
