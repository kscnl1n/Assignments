/*
Name: Kaylee Scanlin

Course: COSC 1436, Section 2001

Due Date: October 13th, 2023

Assignment Description: Write a program that asks the user for a file name. (20pts)
Assume the file contains a series of numbers, each written on a separate line.
The program should read the contents of the file into an array then display the following data: (20 pts)

- The lowest number in the array (10 pts)
- The highest number in the array (10 pts)
- The total of the numbers in the array (20 pts)
- The average of the numbers in the array (20 pts)

Assignment Purpose: The purpose of the following program is to read in a file from the user and input
its data into an array. The program will then use functions and for loops to scan the values of this array,
and output the lowest and highest values, as well as the average of the numbers in the array.

*/

#include <iostream>
#include <fstream>      // To include the file stream objects necessary for getting files together.
#include <string>       // To include the string object to store file name.
using namespace std;
int main()
{
    // 1. NAME VARIABLES/OBJECTS NECESSARY FOR PROGRAM FUNCTIONALITY:

    // String value for the file name.

    string filename;

    // Integer values for the capacity of the array (entered by the user); and doubles for the total of the numbers in the array
    // (used to calculate the average later), for the smallest number in the array, and for the largest number in the array.

    int CAPACITY = 0;
    double number_total = 0, smallest_number, largest_number;

    ifstream arrayFile;

    // 2. PROMPT USER FOR INPUT & 3. STORE USER INPUT:

    // Prompting user to input their file name as a string.

    cout << "Enter file name (include extension!): ";

    cin >> filename;

    // This part of the code was a bit experimental.

    // Since there doesn't appear to be a way to way to set the capacity of an array to the exact length of the file
    // in C++ - at least, not from what we've learned - I prompted the user to enter the capacity of the array the
    // numbers in their file will be stored in.

    cout << "Enter the capacity for the array your numbers will be stored in: ";

    cin >> CAPACITY;

    double fileNumbers[CAPACITY] = {0};

    arrayFile.open(filename);

    // Double-checking to see that the user entered the correct file name.

    if (!arrayFile)
    {
        cout << "Sorry, I couldn't find that file. Please ensure the file is stored in the same folder as this program." << endl;
    }

    //4. CALCULATIONS & INTERNAL LOGIC:

    // Here, we need to read the contents of the file into the array fileNumbers.
    // We will use a while loop instead of a for loop to do so to ensure that we don't run over the array's capacity.

    // Defining counter variable (this represents the exact location in the array we're in during each loop):

    int i = 0;

    // The while loop occurs while the counter value (i) is less than or equal to the size of the array capacity,
    // and each iteration of it feeds a value from the arrayFile into the storage space in the fileNumbers array at i.

    // To understand this code, we need to remember that the arguments passed into the parenthesis of the while loop
    // are actually running. So when we run while (arrayFile >> fileNumbers[i] && i <= CAPACITY), we're actually feeding
    // the values stored in arrayFile into the ith storage location in the array (arrayFile >> fileNumbers[i])
    // and we're running comparisons between the value of i and CAPACITY with each iteration of the loop (&& o <= CAPACITY).

    // We must also read the values of arrayFile into the fileNumbers array first, so we have set values for fileNumbers[0],
    // which will be the default values for the largest_number and smallest_number values before the while loop cycling through
    // each index of the array runs for the first time--though we could also leave arrayFile >> fileNumbers[i] inside of the while
    // loop and it would still work.

    // **THIS HAS TO BE OUTSIDE OF THE WHILE LOOP! Otherwise it'll set the values of largest_number and smallest_number back to fileNumbers[0]
    // every time the loop iterates.

    arrayFile >> fileNumbers[i];

    largest_number = fileNumbers[0];

    smallest_number = fileNumbers[0];

    while (arrayFile >> fileNumbers[i] && i <= CAPACITY)
        {

            // Inside of this array, we're going to use a set of if/else statements to set the values of the four global
            // variables we have set for the lowest and highest number of the array, as well as the values for the total amount of numbers in the array, and
            // the average of the numbers in the array.


            // First if statement: if the value in fileNumbers[i] is greater than the value in largest_number.

            if (fileNumbers[i] > largest_number)
                {
                    largest_number = fileNumbers[i];

                }

            // Second if statement: if the value in fileNumbers[i] is less than the value in smallest_number.

            else if (fileNumbers[i] < smallest_number)
                    {
                        smallest_number = fileNumbers[i];

                    }


            // If the numbers in fileNumbers[i] aren't different from the largest_number/smallest_number, the value in largest_number
            // and smallest_number will remain the same by default.

            // Now we can do the easy parts:

            // Add the number at the ith point in the array to the value number_total, which adds all of the numbers in the array together.

            number_total = number_total + fileNumbers[i];

            // Iterating the counter.

            i++;

            // IMPORTANT: The counter value is now equal to the number of elements in the array. We can use this to calculate the average of the numbers inside of it.

        }

    // Closing our file to prevent data issues now that our array is full.

    arrayFile.close();

    // 5. DISPLAY OUTPUT:

    // Displaying the number of elements currently stored in the array using variable i.

    // Displaying the largest and smallest numbers.

    cout << endl << "The lowest number in the array is " << smallest_number << endl;

    cout << "The highest number in the array is " << largest_number << endl;

    cout << endl << "the number of elements currently stored in the array is " << i << endl;

    // Displaying the average of all of the elements in the array, which should be equal to the number_total value (every value in the array added together)
    // divided by the counter variable i.

    cout << "the average of the elements currently stored in the array is " << (number_total)/i << endl;


    return 0;

}
