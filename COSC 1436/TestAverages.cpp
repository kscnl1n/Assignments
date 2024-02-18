/* Name: Kaylee Scanlin
Date 09/12/2023
Course: COSC 1436
Section: 2001

Description: Write a program that asks for five test scores. The program should
calculate the average test score and display it. The number displayed
should be formatted in fixed-point notation, with one decimal point of
precision

*/


#include <iostream>
#include <iomanip> // for stream manipulators
using namespace std;

// Function prototype - to let the program know I create this function later
// I wasn't sure if I had to put all of the variables inside of each function every time I called it so
// I created and initialized double variables to store the values of each score every time I called it.
void averages(double num1, double num2, double num3, double num4, double num5);


int main()
{
    //1. Naming variables
    double score1, score2, score3, score4, score5;

    //2. Prompting user for input
    cout << "Enter five numbers: ";

    //3. Storing input
    cin >> score1 >> score2 >> score3 >> score4 >> score5;

    // Calling the function that will calculate and display the value of the average of 5 test scores.
    averages(score1, score2, score3, score4, score5);

    return 0;
}

void averages(double num1, double num2, double num3, double num4, double num5)
{
    double average = (num1 + num2 + num3 + num4 + num5)/5;

    cout << "The averages of these scores is " << fixed << setprecision(1) << average << "." << endl;

}
