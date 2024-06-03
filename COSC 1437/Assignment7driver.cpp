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


// THIS IS THE DRIVER/TEST FILE FOR THE CLASS DATE- actual class will be in Assignment7.cpp!

// Including our file containing the date class:
#include "Date.cpp"
// For cin/cout.
#include <iostream>
// So we don't have to type std::cout or std::cin every time we want to use cout/cin.
using namespace std;

//Beginning of main function, where we will test the Date class:
int main()
{

// Example of the Date class with provided date (12/8/2018):

cout << "Here is the hard-coded example: " << endl; // Output a message indicating the start of the hard-coded example.

    try // Start of try block to catch potential exceptions.

    {
        Date date(12, 25, 2018); // Create a Date object with the provided date (12/8/2018). The constructor of the Date class is called with the month, day, and year as arguments.

        date.printFormat1(); // Calling the printFormat1 function to print the date in format 1, which is mm/dd/yyyy.

        date.printFormat2(); // Calling the printFormat2 function to print the date in format 2, which is Month dd, yyyy.

        date.printFormat3(); // Calling the printFormat3 function to print the date in format 3, which is dd Month yyyy.

    }

        // Catch block to handle InvalidDay exceptions. InvalidDay is a nested exception class within the Date class.
        // Catch blocks are used in exception handling to handle and respond to specific types of exceptions that may be thrown within a try block.
        // When an exception is "thrown" (found) within the try block, the program searches for a catch block that matches the type of the thrown exception.
        // They're particularly useful when debugging.

        catch (const Date::InvalidDay& e)

            {
                // Output an error message for InvalidDay exception.
                // In c++, an "exception" is defined as anything that disrupts the normal flow of a program.
                // This usually refers to errors.

                cout << "Exception: " << e.what() << endl;

            }

                catch (const Date::InvalidMonth& e)

                    {
                        // Catch block to handle InvalidMonth exceptions. InvalidMonth is a nested exception class within the Date class.

                        cout << "Exception: " << e.what() << endl;

                    }

// Example of the Date class where the user is prompted for input date, to make it easier to grade:

cout << endl << "Here is an example that includes user input, so it's easier to test the functions: " << endl << endl;

// Declaring variables for storing the month, day, and year- these can be integers, since you can't have half a day, or half a year!

int month, day, year;

// Prompting the user for input for month, day, and year:

cout << "Enter a month in two-digit format: ";

cin >> month;

cout << "Enter a day in two-digit format: ";

cin >> day;

cout << "Enter a year in four-digit format: ";

cin >> year;

// endline for formatting on screen:

cout << endl;


     // Try block to catch potential exceptions:

    try
        {
            // Creation of the Date object with the user-provided date.

            Date date(month, day, year);

            // Call Format 1, mm/dd/yyyy.

            date.printFormat1();

            // Format 2, Month dd yyyy.

            date.printFormat2();

            // Format 3, dd Month yyyy.

            date.printFormat3();

        }

            // Catch block to handle InvalidMonth exceptions. InvalidMonth is a nested exception class within the Date class.
            // In C++, a try block is a block of code that is used to enclose statements that might potentially throw exceptions. The try block is followed by one
            // or more catch blocks, which are used to handle any exceptions that are thrown within the try block. When an exception occurs within the try block,
            // the program searches for a matching catch block that can handle the type of exception thrown. If a matching catch block is found, the code within
            // that catch block is executed to handle the exception.

            catch (const Date::InvalidMonth& e)

                {

                    // If month is invalid:

                    cout << "Exception caught: " << e.what() << endl;
                }

                    catch (const Date::InvalidDay& e)

                    {

                        // If day is invalid:

                            cout << "Exception caught: " << e.what() << endl; // Output an error message for InvalidDay exception.

    }

    // End of program.


    return 0;

}
