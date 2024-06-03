// Program by Kaylee Scanlin
// COSC 1437
// Due: 04/21/2024
// The purpose of the following program is to create a class to store and print out specific dates,
// with error handling.

/* ASSIGNMENT INSTRUCTIONS: Design a class called Date. The class should store a date in three integers: month, day, and year.
There should be member functions to print the date in the following forms:

12/25/2018

December 25, 2018

25 December 2018

The class should implement the following exception classes:

InvalidDay    Throw when an invalid day (< 1 or > 31) is passed to the class.
InvalidMonth    Throw when an invalid month (< 1 or > 12) is passed to the class.

Demonstrate the class in a driver program. */

#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

public:
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    void printFormat1() {
        cout << month << "/" << day << "/" << year << endl;
    }

    void printFormat2() {
        cout << months[month - 1] << " " << day << ", " << year << endl;
    }

    void printFormat3() {
        cout << day << " " << months[month - 1] << " " << year << endl;
    }

    }
};
