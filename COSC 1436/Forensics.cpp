/*
Name: Kaylee Scanlin

Course: COSC 1436, Section 2001

Due Date: October 6th, 2023


Assignment Description: Forensics experts collect data from crime scenes and use mathematics to help solve some unanswered questions about the crime.
 One of the physical tools they use are calipers to measure the length and width of blood drops or hair follicles.
 To determine angles of impact they use the law of sine and even the law of tangents to calculate the height of the source.

Create a program that will allow investigators to type in their measurement findings and output answers to help in their investigation.

Create a project named Forensics with two major functions getHairType and getHeight.
Be sure to use at least four variables, medullaDiameter, entireHair, femurHeight, and gender.


Assignment Purpose: The purpose of the following program is to teach us how to use functions to make object-oriented programming easier, as well
as get us comfortable with using functions. To do so, we will be creating a program with two functions:

1. hairType
Determines whether or not the hair is human or animal by determining the ratio of the diameter of the medulla to the diameter of the entire hair.
Animal hair = .5 or higher
Human hair = lower than .5
Should return a 1 for human hair and a 0 for animal hair
Takes as input the diameter of the medulla and the diameter of the entire hair in mm

2.getHeight
A person's height can be estimated using the femur using the formulas

male - height = 69.089 + 2.238f (f stands for the femur length in cm)
female - height = 61.412 + 2.317f  (f stands for the femur length in cm)

getHeight should receive as an integer 0 for male and 1 for female
it should return the height in cm

*/



#include <iostream> // including the iostream header file with cin and cout.
#include <iomanip> // including the iomanip header file for our stream manipulators which we will use to display our values at the end of our program.
#include <cmath> // to help us round our height up later on (ensures accuracy with the measurements).
using namespace std;



// Defining the getHeight function:
// This function calculates and returns the estimated height of the femur owner.
// As input, it takes MorF (the value 0 or 1 entered by the user to determine whether or not it belonged to a man or woman),
// and as output it returns the height in cm as a double.

double getHeight(int MorF, double femurLength)
{
    double height;

    if (MorF == 0)
        {
            height = 69.089 + (2.238 * femurLength);
        }

    else
        {
            height = 61.412 + (2.317 * femurLength);
        }

    return height;
}


// Defining the hairType function:
// This function calculates and returns whether or not the hair owner is a human or animal.
// As input, it takes the medulla and hair width in mm, and it returns a 0 (animal) or 1 (human)
// depending on whether or not the hair was human or animal.


int hairType(double medullaW, double hairW)
{
    // Defining the variables needed for function to perform its task.

    double hairRatio; // declaring variable for the ratio of the
    // medulla diameter to hair diameter.

    int type; // declaring variable for storing the type of hair.

    hairRatio = medullaW/hairW;

    // If/else statement to set the int type to 1 or 0 depending on whether it is human (1) or animal (0).

    if (hairRatio < .5)
        {
            type = 1;
        }
    else
        {
            type = 0;
        }

    return type;
}



// Our main function--AKA where our program starts.

int main()
{
    cout << "Welcome inspector, " << endl;

    // Declaring the variables we'll need.

    int MorF, humOrAnim; // These are the two T/F or 0/1 numbers we'll be using to determine whether
    // the femur belonged to a man or a woman (entered by user), or if the hair belongs to a human
    // or animal (determined by hairType function).

    double height; // Double for the estimated height of the femur owner, which we will be calculating.

    double medullaW, hairW, hairRatio, femurLength; // Doubles for the medulla width, hair width, hair ratio, and femur length respectively.

    //2. & 3. Prompting user for input and storing it

    cout << "Hair analysis: " << endl;

    cout << "Please enter the medulla width in mm: ";

    cin >> medullaW;

    cout << "Please enter the entire hair width in mm: ";

    cin >> hairW;

    cout << endl << "Height analysis: " << endl;

    cout << "please enter the gender (0 for male 1 for female): ";

    cin >> MorF;

    cout << "Please enter the femur length in cm: ";

    cin >> femurLength;



    // 4. & 5. Calculations/logic &

    // If/Else statement for whether the hair is human or animal.
    // We're using the value in humOrAnim, which stores the returned integer value from the hairType
    // function, to determine which message we should display (human or animal).

    humOrAnim = hairType(medullaW, hairW);

    // Since humOrAnim is equal to the value returned in the hairType function, it is set to 1 for human hair,
    // and 0 for animal hair.

    // Because of this, we can use an if/else statement to display our output for whether it is human or animal hair.

    if (humOrAnim == 1)
        {
            cout << "The sample provided is from a human" << endl;
        }
    else
        {
            cout << "The sample provided is from an animal" << endl;
        }

    // Thankfully, for the height, we don't have to write something nearly as complicated--we can simply print the height
    // value returned by the getHeight function to the screen. Setprecision is used to display it to the third decimal place
    // to match the example in the problem.

    height = getHeight(MorF, femurLength);

    cout << fixed << setprecision(3) << "The height is estimated to be " << height << endl;

    // termination of our program.

    return 0;

}

