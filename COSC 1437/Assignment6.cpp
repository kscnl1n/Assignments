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


// Header file for cin/cout.

#include <iostream>

// So we don't have to type in std:: before each cin/cout object:

using namespace std;

// Creation of the Money class:

class Money {

    // Access specifier for the public data members - visible to other functions and classes
public:

    // Amount in dollars
    int amount;

    // Amount in cents
    int cents;

    // Convert to cents function
    int toCents() {
        return (amount * 100 + cents);
    }

    // Static function to convert cents to Money
    static Money centsToMoney(unsigned int cents) {
        if (cents == 0) {
            // Initialize Money object with 0 dollars and 0 cents
            Money ret(0, 0);
            return ret;
        } else {
            // Initialize Money object with converted dollars and cents
            Money ret(cents / 100, cents % 100);
            return ret;
        }
    }

    // Void function to print out calculated amounts to the screen.
    void display() {
        cout << '$' << amount << '.' << cents;
    }

    // Money class constructor:
    Money(int x, int y) {
        amount = x;
        cents = y;
        if (cents > 100) {
            cents = y % 100;
            amount = amount + (y / 100);
        }
    }

    // Overloaded + operator
    Money operator+(Money obj) {
        int total = obj.toCents() + this->toCents();
        return centsToMoney(total);
    }

    // Overloaded - operator
    Money operator-(Money obj) {
        int value1 = obj.toCents();
        int value2 = this->toCents();
        int total;
        if (value1 > value2) {
            total = value1 - value2;
        } else {
            total = value2 - value1;
        }
        return centsToMoney(total);
    }

    // Overloaded *= operator
    void operator*=(int value) {
        int totalCents = this->toCents();
        totalCents *= value;
        amount = totalCents / 100;
        cents = totalCents % 100;
    }

    // Overloaded /= operator
    void operator/=(unsigned int value) {
        unsigned int totalCents = this->toCents();
        totalCents /= value;
        amount = totalCents / 100;
        cents = totalCents % 100;
    }

    // Overloaded > operator
    bool operator>(Money obj) {
        return this->toCents() > obj.toCents();
    }

    // Overloaded != operator
    bool operator!=(Money obj) {
        return this->toCents() != obj.toCents();
    }

    // Overloaded < operator
    bool operator<(Money obj) {
        return this->toCents() < obj.toCents();
    }

    // Overloaded <= operator
    bool operator<=(Money obj) {
        return this->toCents() <= obj.toCents();
    }

    // Overloaded >= operator
    bool operator>=(Money obj) {
        return this->toCents() >= obj.toCents();
    }

    // Overloaded == operator
    bool operator==(Money obj) {
        return this->toCents() == obj.toCents();
    }
};

// Starting our program:
int main() {

    // Test values:
    // These are arbitrary and only set to these values.
    // Money 3 is going to be set equal to money1 + money2, so we set it equal to zero here!
    Money m1(4, 5);
    Money m2(18, 26);
    Money m3(0, 0);

    // Displaying information about our m1 and m2 values:
    cout << "Information about money1: ";
    m1.display();
    cout << endl;

    cout << "Information about money2: ";
    m2.display();
    cout << endl;

    // Arithmetic to add the values (+):
    m3 = m1 + m2;
    m1.display();
    cout << " + ";
    m2.display();
    cout << " = ";
    m3.display();
    cout << endl;

    // Arithmetic to subtract the values (-):
    m3 = m1 - m2;
    m1.display();
    cout << " - ";
    m2.display();
    cout << " = ";
    m3.display();
    cout << endl;

    // Arithmetic to determine which value is greater (>):
    bool b = m1 > m2;
    m1.display();
    cout << " > ";
    m2.display();
    cout << " = " << b << endl;

    // Arithmetic to determine which value is lesser (<):
    b = m1 < m2;
    m1.display();
    cout << " < ";
    m2.display();
    cout << " = " << b << endl;

    // Arithmetic to multiply the values (*):
    m1.display();
    m1 *= 2;
    cout << " *=2 = ";
    m1.display();
    cout << endl;

    // Arithmetic to divide the values (/):
    m1.display();
    m1 /= 2;
    cout << " /=2 = ";
    m1.display();
    cout << endl;

    return 0;

}
