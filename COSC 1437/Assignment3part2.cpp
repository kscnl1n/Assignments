// Program by Kaylee Scanlin
// COSC 1437
// Due: 02/25/2024
// The purpose of the following program is to create a function that finds the count of a given character in a C++ string.
// It will then test the function in this program.


/* ASSIGNMENT INSTRUCTIONS:
Write a function that converts all characters in a C++ string to uppercase. Test the function in a program. */


// For cin/cout object.
#include <iostream>

// For string manipulation.
#include <iomanip>

// For c++ strings.
#include <string>

using namespace std;

 // 1. CREATING THE FUNCTION

    // First, we must create the function we are using to cycle through each space in the array of the string,
    // and then convert it to uppercase by taking advantage of the fact that each lowercase letter's ASCII code is
    // 32 higher than the uppercase letters.
    // Since
    // A = 65
    // and
    // a = 97
    // Theoretically, if we subtract 32 from any lowercase ASCII letter's code, we would have the uppercase letter
    // returned to us.

void uppercase(string a)
{
    // Defining the counters for the number of times the character appears in the string (countNumber) and
    // the place we're at in the array.

    int countNumber = 0;

    int arrayPlace = 0;

    // For loop to cycle through each value in our string and print the uppercase letter.

    for (arrayPlace = 0; arrayPlace < a.length(); arrayPlace++)
    {

    char characterAt = a.at(arrayPlace);

        // fallback if/else statements in case the string contains any non-letter characters.

        if (characterAt < 65)
        {
            cout << characterAt;
        }

        else if (characterAt >= 65 || characterAt <= 89)
        {
            char lowercase = characterAt - 32;

            cout << lowercase;
        }

        else if (characterAt > 89 && characterAt < 97)
        {
            cout << characterAt;
        }

        else if (characterAt >= 97 || characterAt <= 122)
        {
            char lowercase = characterAt - 32;

            cout << lowercase;
        }

    }

}


int main()
{
    // 1. DEFINING THE STRING OBJECT

    string string1;

    // 2. ASKING USER FOR INPUT
    // Here we will ask the user to enter a string of any length and then store it within a c++ object.

    cout << "The following program will convert your lowercase string to an uppercase string." << endl;

    cout << "Enter a string: " << endl;

    // getline to save whitespaces in our string.

    getline(cin, string1);

    // 3. CALLING THE FUNCTION

    // Now we must call the function we created to return the string we have in all uppercase letters.

    uppercase(string1);

    return 0;
}
