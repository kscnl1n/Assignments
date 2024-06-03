// Program by Kaylee Scanlin
// COSC 1437
// Due: 03/10/2024
// The purpose of the following program is to create a class to define a square by its length and width.
// Then, we will be using functions to find the perimeter and area of the square shape. We will repeat this for cubes as well.

// ASSIGNMENT INSTRUCTIONS: create a class that defines a square geometric shape. The class must have a data member named side
// that defines the length of each side. Then define two member functions, getPeri and getArea, to find the perimeter and area of the square shape.
// Now define a Cube that defines a cubic shape and inherits from the Square class. The class Cube needs no new data members, but it needs the member
// functions getArea and getVolume. Provide the appropriate constructors and destructors for both classes.


// For cin/cout object.
#include <iostream>

// For strings.
#include <string>

// Defining namespace
using namespace std;

// First, we must create our class "Square" that defines a square geometric shape.
class Square
{

    // ACCESS SPECIFIER
    // Ensure you specify the domain of the class-
    // Since we will be using the functions within it in the main
    // function, we must set this to public.
    // If we were to set this to private, only members
    // of the class could access it.

    // DATA MEMBERS
    // a. Data members are side (to store the length of each side)
    // MEMBER FUNCTIONS
    // b. Member functions are getPeri and getArea, which will find the
    // perimeter and area of the square shape respectively.

   // ACCESS
   // We will need all data members and functions to be public in this case because of how we'll be accessing
   // them after the cube class inherits data from the square class.

    protected:

    double side; // Data member to store the side length

    public:

        // double side; // Data member to store the side length

        // Constructor to initialize the side length:
        // (Empty function)
            Square(double sideLength) : side(sideLength)
                {

                }

        // Member function getPeri to get the perimeter of the square:
            double getPeri()
                {

                    return 4 * side;

                }

        // Member function getArea to get the area of the square:
            double getArea()
                {

                    return side * side;

                }

        // Destructor function!
        ~Square()
            {
                cout << endl;

                cout << "Square object destroyed" << endl;

            }

};

// Create a class named "Cube" that inherits getArea and getPeri results from "Square" (AKA the public functions):

class Cube : public Square
{

    public:

            // Constructor to inherit side length from Square class:
            // (Empty function)
            Cube(double sideLength) : Square(sideLength)
                {

                }

            // Member function to get the volume of the cube
            double getVolume()
                {

                    return side * side * side;

                }

    // Member function to get the area of the cube:
    double getArea()
        {

            return 6 * (side * side * side);

        }

    // Don't forget the destructor!
    ~Cube()
        {

            cout << endl;

            cout << "Cube object destroyed" << endl;

        }

};


// Calling main:
// Where our program will actually begin.
// I have also included some code that prompts the user for a side length for the cube and the square- hopefully that is ok.

int main()

        {
            // Variable storage for user input (side length of square and cube, and units used):

            double squareLength, cubeLength;

            string units;

            // Prompting user for input:

            cout << "Enter the units used in measurement: ";

            cin >> units;

            cout << "Enter the length of the square in " << units << ": ";

            cin >> squareLength;

            cout << "Enter the length of the cube in " << units << ": ";

            cin >> cubeLength;

            // Extra endl to make output look visually appealing.

            cout << endl;

            // NOW:
            // We can create a Square object with an arbitrary side length chosen by the user:

            Square userSquare(squareLength);

            cout << "Square Perimeter: " << userSquare.getPeri() << " " << units << "." << endl;

            cout << "Square Area: " << userSquare.getArea() << " " << units << "." << endl;

            // Divider for visual appeal.

            cout << "==========================================" << endl;

            // And create a Cube object with an arbitrary side length chosen by the user:

            Cube userCube(cubeLength);

            cout << "Cube Perimeter: " << userCube.getPeri() << " " << units << "." << endl;

            cout << "Cube Area: " << userCube.getArea() << " " << units << "." << endl;

            cout << "Cube Volume: " << userCube.getVolume() << " " << units << "." << endl;

            cout << "==========================================" << endl;

        // End of program.

    return 0;

}
