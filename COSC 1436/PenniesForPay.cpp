/*
Name: Kaylee Scanlin

Course: COSC 1436, Section 2001

Due Date: September 29, 2023

Assignment Description: Write a program that calculates the amount of money a person would earn over a period of time if his or her
salary is one penny the first day, two pennies the second day, and continues to double each day. (50 pts)

The program should ask the user for the number of days (20 pts) . Display a table showing what the salary was for each
day, and then show the total pay at the end of the period (10 pts). The output should be displayed in a dollar amount, not
the number of pennies (10 pts).

Purpose: In this assignment, we will be using our first loop to keep track of how many USD are earned per day.

*/

#include <iostream> // Header file for cin/cout
#include <iomanip> // Header file for stream manipulators, which we can use to display our data in a more aesthetically-pleasing way
#include <cmath> // Header file for the Pow function, which we will be using to exponentiate
using namespace std;
int main()
{

    // 1. DEFINING VARIABLES

    int days; // to keep track of the number of days the worker has been working.

    double pennies; // to keep track of the total number of pennies the user has earned day-to-day.

    double totalEarned; // to store how much the worker will earn in total after the number of days has passed.

    // 2. TALKING TO USER
    // Here we'll ask and record how many days they have been working.

    cout << "Enter the number of days the worker has been working: ";

    //3. STORING USER INPUT IN VARIABLES

    cin >> days;


    //Error checking.

    if (days < 1)
    {

        cout << "Invalid number of days." << endl;

    }

    else {

        // Printing a display of the day and USD earned for a nice UX.
        // The programming instructions told us to put "Pennies" instead of "usd" here,
        // but I used USD instead because it is more accurate to the number we are trying to display.

        cout << endl << "Day        USD" << endl;

        cout << "-------------------------" << endl;


        // 4. INTERNAL LOGIC & CALCULATIONS
        // For loop to calculate how many pennies the user is earning per day.
        // Here, the counter is an integer value initialized to 1 (counter = 1). According to the syntax of the for loop,
        // until the counter value reaches the number of days (counter <= days), the counter value will iterate by 1 and repeat the
        // processes outlined in the for loop until this number is reached.
        // The for loop itself calculates how many pennies the user has made up until that day, how much money that is in USD, and prints
        // it out to the screen for each day.
        // **Note that the number of the day we are on is equal to the counter number.
        // So, in this for loop, the counter is the the internal equivalent to the external variable 'days'.


        for (int counter = 1; counter <= days; counter++)
            {

            // 1. DEFINING VARIABLES
            // Here, I have defined variables called 'salary' and 'pennies' for the scope of this for loop only.
            // It is okay to have a second variable titled 'pennies' because this one is limited to the scope of
            // the inside of this for loop.
            // Salary will be a double value that we'll use to store the total amount earned in USD,
            // and pennies will be an integer value that we'll use to store the total amount of pennies earned until that day.

                double pennies = pow(2, (counter - 1)); // Since the # of pennies we earn daily doubles, we simply exponentiate 2 to the power of
                                                        // whatever day we are on--minus one, because on the first day we started off with only 1 penny,
                                                        // but we can't exponentiate 1 because any power of 1 is equal to 1.

                double salary = 0.01 * pennies;  // Simple math to convert the total # of pennies earned to USD (1 penny = 0.01 USD).

                // Displaying the total amount of USD earned that day:

                cout << left << setw(11) << counter;

                cout << right << "$" << fixed << setprecision(2) << salary << endl;

            }

        // Exiting the for loop.
        // The only function we need to iterate in this program is the calculation of USD earned every day, so we can stop using
        // our for loop here.

        // Now we will initialize the double 'pennies', which we defined in the main function earlier, and set it equal to the number
        // of pennies earned using the same math as we did for the pennies value in the for loop--however, we will not be using the counter as our
        // exponent value, but the total number of days total, since we don't have to calculate the number of pennies earned for each individual day.
        // We will also subtract one penny because the following arithmetic assumes we are starting with 1 penny, not zero, due to use exponentiating
        // 2 and not 1.

        pennies = (pow(2, days) - 1);

        // Now we will initialize the double totalEarned to the number of USD we have earned in total.

        totalEarned = pennies * 0.01;

        //5. DISPLAY CALCULATIONS
        // Here, we will display our calculations for our data.

        cout << "The total salary for " << days << " days is: $" << totalEarned << endl;

        // End of program.

    // end of Else statement.

    }

    return 0;

}
