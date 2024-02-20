// Program by Kaylee Scanlin
// COSC 1437
// Due: 01/28/2024
// The purpose of the following program is to create a class called Employee, which will store multiple data objects of different types.

// As input, the program will take a string, two integers, and a double meant to be "read in" from a file. These are meant to be arrays
// containing the employee's name, age, years of service, and salary.
// As output, the program will print text output of the employee's name, age, years of service, and salary to the screen.

/* ASSIGNMENT INSTRUCTIONS: Define a class name Employee as follows:

a. Data members are name, age, serviceYear, salary.

b. Define a parameter constructor and a destructor.

c. Accessor member functions are getName, getAge, getServiceYear, and getSalary.

and use the file saved as employee.h to test your employee.cpp class you created above.

(open in another folder). */

#include <iostream>
#include <string>
#include <iomanip>
// #include "employee.h"
using namespace std;

// Define a class name Employee as follows:
// a. Data members are name, age, serviceYear, salary.

class Employee
{
    // ACCESS SPECIFIER
    // Ensure you specify the domain of the class-
    // Since we will be using the functions within it in the main
    // function, we must set this to public.
    // If we were to set this to private, only members of the class could access it.

    // DATA MEMBERS
    // a. Data members are name, age, serviceYear, salary.

    // PRIVATE: these are members of the class that only our class will need to access.
    // Since we'll be calling the class Employee in main, we can put the data members under private,
    // since the only thing that will be accessing them is our class itself. We will be using these to
    // manipulate data in the class later.

    private:
        string name;
        int age;
        int serviceYear;
        double salary;

    // PUBLIC: These are the members of the class we'll be calling in main. One of them is our parameterized constructor (employeeData "function").
    // Here, we will put the accessor member functions, constructor, and destructor.

    public:
        // PARAMETERIZED CONSTRUCTOR
        // This parameterizes constructor employeeData will assign argument values to the properties within.

        Employee(string name, int age, int serviceyear, double salary)
        {
            // Calling functions that will assign the data members values from main.

            setName(name);
            setAge(age);
            setServiceYear(serviceyear);
            setSalary(salary);

        }

        // CLASS DESTRUCTOR
        // A destructor is a special member function that is called when an object goes out of scope.
        // It prints a message indicating that the employee's data has been destroyed, and is denoted by the tilde(~) before the class.

        ~Employee()
            {
                cout << "Employee " << name << "'s data has been destroyed." << endl;
            }

        // ACCESSOR MEMBER FUNCTIONS
        // These functions allow getting and setting the values of the private data members.
        // They are used for controlling access to the class data from outside functions (ex: main)
        // as well as for encapsulation.

        // the void functions set___ will take as input the value from main and set the private data member's value within our class to it.

        void setName(string Name)
            {
                name = Name;
            }

        void setAge(int Age)
            {
                age = Age;
            }

        void setServiceYear(int ServiceYear)
            {
                serviceYear = ServiceYear;
            }

        void setSalary(double Salary)
            {
                salary = Salary;
            }

        // the non-void functions get____ will return these private data member's values to main when called in main.
        // this works despite these data members being private because the non-void functions themselves are public,
        // so main can access them, which can in turn access private.

        string getName()
            {
                return name;
            }

        int getAge()
            {
                return age;
            }

        int getServiceYear()
            {
                return serviceYear;
            }

        double getSalary()
            {
                return salary;
            }


};

int main()
{

// Taken from the employee.h file given to us under Assignment1.

// 1 instance of the class is created (employee) with data members ("Mary", 24, 2, and 67000).

Employee employee ("Mary", 24, 2, 67000);

// Printing information about the employee:

cout << "Information for employee: " << endl;

cout << "Name: " << employee.getName() << endl;

cout << "Age: " << employee.getAge() << endl;

cout << "Number of year(s) in service: ";

cout << employee.getServiceYear() << endl;

cout << "Salary: " << fixed << setprecision (2);

cout << employee.getSalary() << endl;

return 0;

    return 0;
}
