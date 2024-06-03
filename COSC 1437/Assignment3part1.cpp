// Program by Kaylee Scanlin
// COSC 1437
// Due: 02/25/2024
// The purpose of the following program is to create a function that finds the count of a given character in a C++ string.
// It will then test the function in this program.


/* ASSIGNMENT INSTRUCTIONS:
Write a function that finds the count of a given character in a C++ string. Test the function in a program.
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
    // keep track of how many times the character 'counter' appears, and then print it out.
    // To do so, we will need a for loop and a while loop.
    // This will be an int function, because it will be returning an integer in main.



int countChar(string a, char b)
{
    // Defining the counters for the number of times the character appears in the string (countNumber) and
    // the place we're at in the array.

    int countNumber = 0;

    int arrayPlace = 0;

    // For loop to cycle through each value in our string.

    for (arrayPlace = 0; arrayPlace < a.length(); arrayPlace++)
    {
        char characterAt = a.at(arrayPlace);

        if (characterAt == b)
        {
            countNumber++;
        }

    }

    return countNumber;
}




int main()
{
    // Defining the string object.
    // In C++, there are two primary ways to define a string object:
    // 1. The C-style string, which is really a 1D array of characters followed by a null terminator defined as so:

    // char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    // This C-style string can have operations performed on it with the <cstring> library, and are essentially
    // pointers to the first character of the string. So 'greeting' would be a pointer to the first character in the
    // array.

    // 2. The C++ string using the <string> library, which has a string class automatically built in that can be
    // defined as so:
    // string greeting = "Hello";

    // These string classes can be modified with functions built into the string library such as .length(), which
    // returns the length, and .at(), which returns the character at certain points in the string.
    // Remember that since these string classes are still just arrays of characters, when using the at function,
    // our 'count' starts at 0 for the first letter of the string.

    // 1. CREATING VARIABLES
    // We want to create a c++ string, so we must create a c++ string object for it.
    // We want to store the character the user wants to determine the count of in the string as well, so we
    // must also create a char for it. We also need to create an int value to store the number
    // of times the character appears in the string.

    string string1;

    char countValue;

    int appearances;

    // 2. ASKING USER FOR INPUT
    // Here we will ask the user to enter a string of any length and then store it within a c++ object.

    cout << "The following program will find the length of a given character in a C++ string." << endl;

    cout << "Enter a string: " << endl;

    cin >> string1;

    // Here we will ask the user to enter the character they are trying to find the count of in the aforementioned string.

    cout << "Enter the character you want to find the count of: " << endl;

    cin >> countValue;

    // 3. CALLING THE FUNCTION

    // Now we must call the function we created to return the count of said character in our string.

    appearances = countChar(string1, countValue);

    cout << "String " << string1 << " contains character " << countValue << " " << appearances << " times." << endl;

    return 0;
}
