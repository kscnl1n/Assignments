// Program by Kaylee Scanlin
// COSC 1437
// Due: 03/10/2024
// The purpose of the following program is to create a class that represents an amount of money in dollars and cents.
// we will then be practicing overloading operators, such as the minus and subtraction operators, to perform various
// mathematical operations on the

// ASSIGNMENT INSTRUCTIONS: (A) Create a class Money that represents a money value (combination of dollars and cents).
// Overload the binary plus operator to add two money values to get a new one. (B) Overload the binary minus operator to subtract a money value from
// a larger value to get a new one. Also overload the *= operator to multiply a money value by an integer and /= operator to divide a money value
// by an integer.

// Since no arbitrary monetary amount is given, we will prompt the user for some amounts in dollars and cents for money1 and money2 (our totals
// the program will be doing arithmetic with) and money3, their sum/difference/product/quotient/etc. This will be in the Test_for_assignment_6 file!
// KEEP IN MIND THAT THIS IS ONLY THE CLASS FILE AND IT WILL NOT WORK WITHOUT A TESTING APPLICATION!


// Header file for cin/cout.

#include <iostream>

// So we don't have to type in std:: before each cin/cout object:

using namespace std;

// (A.) Creation of the Money class:

class Money {

private:

    // ACCESS SPECIFIERS: Here in private, the objects will only be accessible in this class, not in any derived classes or
    // in main. We'll put the variables where we're storing the amount of dollars and cents in our money amounts here.
    // These can be in integers, since you can't have half a dollar- that would be measured in whole cents!

    int amountDollars;

    int amountCents;

public:

    // Here in public, we will put the constructor to initialize the Money object with dollars and cents:

    Money( int ad, int ac )
        {
            // Storing the variables for dollars and cents in our Money function.
            // This will assign the private variables to this class, amountDollars and amountCents,
            // the money amounts are entered in main.

            amountDollars = ad;

            amountCents = ac;

        }


    // (B.) NOW WE OVERLOAD OUR OPERATORS -

    // Operator overloading in C++ allows programmer to redefine the behavior of operators (such as +, -, *, /, =, etc.) for user-defined types
    // (classes and structures). It enables programmers to use these operators with objects of one's own classes. It makes code more expressive and intuitive.

    // When one overloads an operator for a class, it defines how that operator should behave when applied to objects of that class.
    // This allows programmers to use familiar operators with custom types, making code more readable and natural.

    // FOR + OPERATOR:

    // Defining the operator+ function, which will overload the + operator.
    // As input it takes the constant object of class money titled 'other', which will only be created in the scope of
    // this operator, with the values from whichever money object (money1 or money2) is sent into it, and returns a new Money object:
    Money operator+ ( const Money other )
        {

            // Arithmetic to determine the total number of cents we have in both money amounts:
            int totalCents = ( amountDollars * 100 + amountCents ) + ( other.amountDollars * 100 + other.amountCents );

            // Arithmetic to return the number of dollars (cents / 100) and cents we have (leftover amount's modulus):
            return Money( totalCents / 100, totalCents % 100 );

        }

    // FOR - OPERATOR:

    // Defining the operator- function, which will overload the - operator.
    // As input it takes the constant object of class money titled 'other', which will only be created in the scope of
    // this operator, with the values from whichever money object (money1 or money2) is sent into it; and returns a new Money object:
    Money operator- ( const Money other )
        {

            int totalCents = ( amountDollars * 100 + amountCents ) - ( other.amountDollars * 100 + other.amountCents );

            // If the total cents being returned is negative, the Money object will return (0,0)- this may happen if
            // the money2 amount is greater than the money1 amount or vice-versa. If this is the case, the operator will return
            // (0,0) to ensure the result is non-negative.
                if ( totalCents < 0 )
                    {

                        return Money( 0, 0 );

                    }

            // Arithmetic to return the number of dollars (cents / 100) and cents we have (leftover amount's modulus):
            return Money( totalCents / 100, totalCents % 100 );
        }

    // FOR * OPERATOR:

    // Defining the operator* function, which will overload the * function.
    // Unlike our earlier functions, this only takes an integer multiplier as input from the user (3 in our case), and
    // returns a new Money object with the amountDollars and amountCents multiplied by 3.
    // EZPZ!
    Money operator*= ( int m )
        {

            // Multiplies the amountDollars member variable of the current Money object by the multiplier value and assigns the
            // result back to amountDollars. This line updates the dollars amount of the Money object.
            amountDollars *= m;

            // Multiplies the amountCents member variable of the current Money object by the multiplier value and assigns the result
            // back to amountCents. This line updates the cents amount of the Money object.
            amountCents *= m;

            // Returning the amount of dollars and cents to main:
            return Money( amountDollars, amountCents );

        }

    // FOR / OPERATOR:
    // Defining the operator/ function, which will overload the / function.
    // This will also only take an integer as a divisor as input from the user (2 in our case), and
    // returns a new Money object with the amountDollars and amountCents divided by 2.
    Money operator/= ( int d )
        {

            int totalCents = ( amountDollars * 100 + amountCents ) / d;

            amountDollars = totalCents / 100;

            amountCents = totalCents % 100;

            return Money( amountDollars, amountCents );

        }

    // Function to print the amount in dollars and cents format to the screen, so the user can see how much money is in each amount.
    // We will use this in our main function in our test file.

    void print()
        {

            cout << "$" << amountDollars << " and " << amountCents << " cents." << endl;

        }

};

