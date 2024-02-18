// Program by Kaylee Scanlin
// COSC 1437
// Due: 01/28/2024
// The purpose of the following program is to create a function that multiplies two fractions and returns the result using pass-by-reference and return-by-reference.

// This program does not require input, but the function multiplyFraction will be receiving instances of the Fraction classes as "input" with pre-encoded
// values of 4/2 and 1/5.

// ASSIGNMENT INSTRUCTIONS:
// Write a function that multiplies two fractions and returns the result using pass-by-reference and return-by-reference. Test your function in a program.

#include <iostream> // for Cin/Cout

using namespace std;

// Creating a class to store fractions.
// Data members: numerator & denominator.
class Fraction
    {
        int numerator, denominator;

        // ACCESS SPECIFIER
        // Ensure you specify the domain of the class-
        // Since we will be using the functions within it in the main
        // function, we must set this to public.
        // If we were to set this to private, only members of the class
        // could access it.

        // PUBLIC: These are the members of the class we'll be calling in main.
        // Notice how we have no private members- this is because

        public:

        // Constructor to initialize the fraction.

            Fraction(int numer = 0, int denom = 1) : numerator(numer), denominator(denom) {}

        // FUNCTION
        // Function to multiply fraction with one another.
        // Notice how fraction is passed by reference thanks to the reference operator! (&)
        // The reference operator creates a new space in memory that points to the fraction,
        // meaning it the original values of the numerator and denominator in main

        void multiply( Fraction& second)
            {
                numerator = numerator * second.numerator;

                denominator = denominator * second.denominator;
            }

    // Function to print the fraction result out to the screen.
    // Although not necessary, this makes it much easier to display our results.
        void print()
            {

                cout << numerator << "/" << denominator;

            }

        };

// Function to multiply two fractions and return the result by reference.

    Fraction& multiplyFractions(Fraction& frac1, Fraction& frac2, Fraction& product)
        {

            product = frac1; // Copy first fraction to product

            product.multiply(frac2); // Multiply with the second fraction

            return product; // Return the product by reference

        }

// MAIN FUNCTION
// This is where our program begins.

int main() {

    // Instantiation for three fractions in main.

    Fraction fraction1(4, 2);

    Fraction fraction2(3, 5);

    Fraction product;

    // Calling multiplyFractions function.

    cout << "The result of multiplying 4/2 and 3/5 is: " << endl;

    multiplyFractions(fraction1, fraction2, product).print();

    return 0;
}
