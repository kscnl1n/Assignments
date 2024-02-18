/*
Program by Kaylee Scanlin

COSC 1436

Created 10/16/2023

ASSIGNMENT DESCRIPTION: A local zoo wants to keep track of how many pounds of food each of its
three monkeys eats each day during a typical week. Write a program
that stores this information in a two-dimensional 3 × 5 array, where
each row represents a different monkey, and each column represents a
different day of the week. The program should first have the user input
the data for each monkey. Then, it should create a report that includes
the following information:
 Average amount of food eaten per day by the whole family of
monkeys.
 The least amount of food eaten during the week by any one
monkey.
 The greatest amount of food eaten during the week by any one
monkey.
Input Validation: Do not accept negative numbers for pounds of food
eaten */

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    // a 2d array is a collection of other arrays.

    int monkeyByDay[3][5];

    // cycling through the monkeys.

    for (int i = 0; i < 3; i++)
        {

            // cycling through the days.

           for (int j = 0; j < 5; j++)
                {
                    cout << "enter the amount of food monkey " << (i + 1) << " ate on day " << (j + 1) << ": ";

                    cin >> monkeyByDay[i][j];

                }

        }


    for (int i = 0; i < 3; i++)
        {
            int j = 0;

            // This array prints up to 5 indices in the array.
            // since we're on the same iteration of the i loop for each
            // iteration of the k loop, and j iterates every time the k loop does,
            // we end up printing a row of values from monkeyByDay[i] with different,
            // incrementing values of [j] (the second dimension), up to the fifth iteration of k
            // when it exits the loop.

            // we exit the k loop just before the i loop prints out an endl, creating another row for our values.

                 for (int k = 0; k < 5; k++)
                {
                    cout << monkeyByDay[i][j] << " ";

                    j++;
                }

        cout << endl;

        }


    return 0;
}
