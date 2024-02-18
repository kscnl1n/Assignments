/* Kaylee Scanlin
COSC 1436
August 31st, 2023
This program will ask the user for their information and display it.
*/

#include <iostream>
#include <string>

using namespace std;
int main()
{


    //1. Variables
    string fname;
    string lname;
    char mInitial;
    string date;
    string course;
    double gpa;
    string major;

    //Talk to the user to ask them for their name.
    cout << "Please enter your first name: ";

    //3. Store the name.
    cin >> fname;

    //2b Talk to the user to ask them for their last name.
    cout << "Please enter your last name: ";

    cin >> lname;

    //2c Talk to the user to ask them for their middle initial.
    cout << "Please enter your middle initial: ";

    cin >> mInitial;

    //2d Talk to the user to ask them for their date
    cout << "Please enter the date: ";
    //3d. Store date - Here, we use the getline function instead of cin, because it allows us to read whitespace into the string variable.
    //Remember that cin skips over whitespace!

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LOOK HERE: COULDNT GET GETLINE WORKING
    getline(cin, date);

    //2e Talk to the user and ask them for their course
    cout << "Please enter the course name and number: ";
    //3e Store the course
    cin >> course;

    //2f Talk to the user and ask them for their major
    cout << "Please enter your major: ";
    //3f Store the major
    cin >> major;

    //2g Talk to the user and ask them for their GPA
    cout << "Please enter your GPA: ";
    //3g Store the GPA
    cin >> gpa;

    //4. Calculation or Logic

    //5. Display
    cout << "Name: " << fname << " " << mInitial << " " << lname << endl;
    cout << "Date: " << date << endl;
    cout << "Course: " << course << endl;
    cout << "Major: " << major << endl;
    cout << "GPA: " << gpa << endl;


    return 0;
}
