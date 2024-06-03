// Program by Kaylee Scanlin
// COSC 1437
// Due: 03/10/2024
// The purpose of the following program is to create the interface and implementation files for the three polymorphic classes
// Employee, SalaryEmployee, and HourlyEmployee.

// INTERFACE VS. IMPLEMENTATION FILES
// In polymorphism, the difference between the interface and the implementation files are critical to know.
// An interface file, often a header file (.h or .hpp), contains class declarations, including member variables
// and function prototypes, serving as a blueprint for how the class should be used without revealing its implementation
//details. On the other hand, an implementation file, typically a source file (.cpp), houses the actual code that implements
// the functionalities declared in the interface file, providing the logic and details behind them. So the interface is the 'blueprint'
// and the implementation files are implementations of these blueprints. In this program, to make it functional, we will be using both.

// ASSIGNMENT INSTRUCTIONS:
/* Hide Folder Information
Instructions
Assume we have the following classes in a polymorphic relationship.

              Employee

^SalaryEmployee      ^HourlyEmployee

The Employee class is an abstract class. An employee has a first name, an initial, and a last name.
A salary employee receives a fixed salary per month. An hourly employee receives wages based on the number
of hours worked per month and a fixed rate/hour. Write the interface files and the implementation files
for all three classes and then test them in an application file. */

// Header file for cout/cin.
#include <iostream>
// Header file for string class.
#include <string>
// Including the std namespace so we don't have to type std:: before each instance of cout and cin.
using namespace std;

// I.

// First, we must create the abstract base class from which the derived classes SalaryEmployee and HourlyEmployee are derived from.

class Employee {

    // In our protected access specifier we have the firstName, lastName, and initial data members.
    // These will store the employee's first name, last name, and middle initial respectively,
    // These will be accessible in the class itself and in any derived classes, but nowhere else.

    protected:

        string fName;

        string lName;

        char initial;

    // in our public access specified we have the constructor for the Employee class.
    // This constructor takes three arguments: fName (reference to the constant string),
    // init (for the initial character), and lName (which is also a reference to a constant string).
    // The constructor initializes the firstName, initial, and lastName member variables with the values
    // passed to it from the protected data members.

    public:

        Employee(const string& fiName, char init, const string& laName)
        : fName(fiName), initial(init), lName(laName) {}

        // Creation of the virtual class destructor.

        virtual ~Employee() {}

        // Creation of the pure virtual earnings function, which we will use to calculate earnings in later
        // derived classes.

        // Virtual functions in C++ are member functions within a base class that are declared with the virtual keyword.
        // They enable dynamic polymorphism, allowing a derived class to override the base class's implementation of the function.
        // At runtime, the best version of the function is called depending on the object type.

        // A pure virtual function is a virtual function declared in a base class, but not implemented.
        // Virtual functions are marked with "= 0", signaling that any derived class must 'plug in' its own version of
        // this function. Here Employee functions as an abstract base class, meaning it is necessary that
        // concrete subclasses to furnish their own implementation for the earnings() function.

        virtual double earnings() const = 0;

        // Declaring a virtual member function to print out the employee's first name, middle initial, and last name.

        virtual void print() const {

        cout << "Employee " << fName << ' ' << initial << ". " << lName;

    }
};


// II.

// Let's create a derived class for the Hourly Employees first, that publicly inherits the Employee class.
// Remember that employees get 1.5x overtime if they go over 40 hours in a workweek,
// and assume hourly employees are paid at a fixed rate.

class HourlyEmployee : public Employee
{

    // Private data members to store the wage and hours worked by the employee as doubles.

    private:

        double wage;

        double hours;


    // Declaring the public constructor taking the constructor from the Employee class.
    // As input, it takes the following arguments: the fName constant string, the initial, and the lName constant string,
    // AKA the employee's first & last names and middle initials.
    // It also takes the hourlyWage double (hourly pay rate for employees) and hoursWorked (hours worked by the employees).

    public:
        HourlyEmployee(const string& fiName, char init, const string& laName, double hourlyWage, double hoursWorked)
        : Employee(fiName, init, laName), wage(hourlyWage), hours(hoursWorked) {}


        // Declaring a virtual member function calculating and returning the earnings of the employee:

        virtual double earnings() const override
        {

            //If/else statement to account for overtime. Both functions return the amount earned by the employee in the month.

            if (hours <= 40)
                {
                    return wage * hours;
                }

            else
                {
                    return 40 * wage + (hours - 40) * wage * 1.5;
                }

        }

        // Virtual function calling the print function in Employee to print out the employee's hourly wage.

    virtual void print() const override
            {

                Employee::print();

                cout << ", hourly wage: " << wage << "$/hour, hours worked total: " << hours << "." << endl;

                // Displaying how many overtime hours were worked, if any.

                if (hours > 40)
                    {
                        double overtime = (hours - 40);

                        cout << overtime << " hours of overtime." << endl;
                    }

            }

};


// III.

// Now let's create a derived class for the salaried employees title SalaryEmployee.
// The class SalaryEmployee will inherit the abstract base class Employee.
// Assume the salaried employee gets a monthly salary!

class SalaryEmployee : public Employee

{

        // Creating a private data member for the monthly salary the employee makes, saved as a double.

        private:

            double monthlySalary;

        // Creating a public constructor for the SalaryEmployee class, derived from the public Employee class in the
        // Employee base class.

        // The constructor takes four parameters: fName (constant string for employee's first name), init (character), lName
        // (another constant string, AKA the employee's last name), and salary (a double). It initializes the firstName, initial, and lastName
        // member variables inherited from the Employee class using the constructor of the Employee class, and initializes
        // the monthlySalary member variable with the salary argument.

        public:

            SalaryEmployee(const string& fiName, char init, const string& laName, double salary)
            : Employee(fiName, init, laName), monthlySalary(salary) {}

        // Declaring a virtual member function named earnings(). It returns the monthlySalary of the SalaryEmployee object.
        // Override allows this function overrides the earnings() function declared in the base class Employee.

        virtual double earnings() const override
        {

            return monthlySalary;

        }

        // Declaring the virtual member function inherited from the base class to print the monthly salary of the employee.

        virtual void print() const override
        {

        Employee::print();

        cout << ", with a monthly salary of " << monthlySalary << "$." << endl;

        }

};


// IV.

// Finally, our program can begin in main:

int main()
{

    // Since Employee is an abstract class, we can't create instances of it, only pointers and references. So, let us create some pointers and references to it for Ms. Selena
    // Gomez, an hourly employee, and Ms. Taylor Swift, a salaried employee.

    HourlyEmployee hourly("Selena", 'M', "Gomez", 20.0, 50);

    SalaryEmployee salaried("Taylor", 'A', "Smith", 3000.0);

    // Declaring an array of pointers to Employee objects to objects named employees.
    // this array for employees stores the salaried and hourly employees we have total,
    // which is two, hence the size.

    Employee *employees[2];

    // Space in array for salaried employees.

    employees[0] = &salaried;

    // Space in array for hourly employees.

    employees[1] = &hourly;

    // Now we can print and calculate earnings using polymorphism using For loop to track each employee.

    for (int i = 0; i < 2; ++i)
        {
            // For loop to iterate through the employees array. For each element, it calls the print() function
            // and prints the earnings of the employee using polymorphism. Since print() and earnings() are virtual
            // functions declared in the Employee class and overridden in the derived classes (HourlyEmployee and SalaryEmployee),
            // the appropriate versions of these functions are called based on the actual type of the object pointed to by the Employee pointers.

            employees[i]->print();

            // Now we can print out the earnings of each employee using the inherited earnings function that has
            // been passed between these inherited classes like a darn volleyball!

            cout << "Earnings: " << employees[i]->earnings() << "$." << endl << endl;

        }

    // Termination of program.

    return 0;
}


