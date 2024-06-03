// Program by Kaylee Scanlin
// COSC 1437
// Due: 05/05/2024
// The purpose of the following program is to utilize templated functions to find the smallest element in an array.
// In C++, templates are a powerful feature that allow you to write generic code, meaning you can define functions and
// classes without specifying the exact data types they will operate on. Instead, you can create templates that can
// work with any data type. For example, you could write a template function to sort an array, and it could be used
// with integers, floating-point numbers, or even custom data types like strings. Templates enable code reusability
// and flexibility, making it easier to write generic algorithms and data structures that can be applied to a wide
//range of data types.

// ASSIGNMENT INSTRUCTIONS: (A) Create a templated function to find the index of the smallest element in an array of any type.
// Test the function with three arrays of type int, double, and char. Then print the value of the smallest element.

// iostream library for cin/cout.
#include <iostream>

// Including the array library for using arrays.
#include <array>

// Using the standard namespace to avoid having to type "std::" before everything.
using namespace std;

// CREATING THE TEMPLATE:

// Define a template function taking a type tempType and a size tempSize.
template <typename tempType, size_t tempSize>

// Define a function 'findSmallest' taking an array 'data'.
int findSmallest(array < tempType, tempSize > data)

    {

        // Set 'smallest' to the first element of the array 'data'.
        tempType smallest = data[0];

        // Initialize the index of the smallest element to 0.
        int smallestIndex = 0;

        // Loop to go through each element of the array 'data'.
        for (int i = 0; i < tempSize; i++)

                {
                    // If statement to check if the current element is smaller than the current smallest.

                    if (data[i] < smallest)

                        {

                            // If yes, update the smallest element.
                            smallest = data[i];

                            // Also update the index of the smallest element.
                            smallestIndex = i;

                        }

                }

        return smallestIndex; // Function returns the index of the smallest element.

    }


// MAIN FUNCTION: Where our program will begin.

int main()
    {
        // Here, we will be prompting the user to input their own values for these arrays.

        // Define our array objects using our array templates for integers, chars, and doubles respectively:

        array <int, 3> intdata;

        array <char, 3> chardata;

        array <double, 3> doubledata;

        // Prompt user for data to put into our 3 separate arrays:

        cout << "Enter 3 integers, separated by a space, for our integer array: ";

        cin >> intdata[0] >> intdata[1] >> intdata[2];

        cout << "Enter 3 characters, separated by a character, for our char array: ";

        cin >> chardata[0] >> chardata[1] >> chardata[2];

        cout << "Enter 3 doubles, separated by a space, for our double array: ";

        cin >> doubledata[0] >> doubledata[1] >> doubledata[2];

        // Print the smallest element of each array:
        // this is possible because the smallestIndex returned in our findSmallest function is set equal to the array's minimum.

        cout << "Smallest element of int array intdata is: " << intdata[findSmallest(intdata)] << " at index " << findSmallest(intdata) << endl;

        cout << "Smallest element of character array chardata is: " << chardata[findSmallest(chardata)] << " at index " << findSmallest(chardata) << endl;

        cout << "Smallest element of double array doubledata is: " << doubledata[findSmallest(doubledata)] << " at index " << findSmallest(doubledata) << endl;

    // end program.

    return 0;

}
