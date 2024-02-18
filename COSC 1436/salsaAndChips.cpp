
/* Write a program that lets a maker of chips and salsa keep track of
sales for five different types of salsa: mild, medium, sweet, hot, and
zesty. The program should use two parallel 5-element arrays: an array
of strings that holds the five salsa names, and an array of integers that
holds the number of jars sold during the past month for each salsa
type. The salsa names should be stored using an initialization list at
the time the name array is created.

The program should prompt the
user to enter the number of jars sold for each type. Once this sales
data has been entered, the program should produce a report that
displays sales for each salsa type, total sales, and the names of the
highest selling and lowest selling products. */


#include <iostream>
#include <string>
using namespace std;
int main()
{

    string salsa[5] = {"mild", "medium", "sweet", "hot", "zesty"};

    // don't forget to put string values in quotes!

    int jars[5];

    //Defining variables to keep track of largest and smallest jar counts.

    string biggestSale, smallestSale;

    int biggestSaleAmount, smallestSaleAmount;

    // This for loop will cycle through all of the values of the salsa array.


            // This for loop will cycle through all of the values of the jars array.

            for (int j = 0; j <5; j++)
                {

                    cout << "Enter the amount of jars sold for " << salsa[j] << " this month: ";

                    cin >> jars[j];

                        if (j == 0)
                        {
                            biggestSale = salsa[j];
                            smallestSale = salsa[j];
                            biggestSaleAmount = jars[j];
                            smallestSaleAmount = jars[j];

                        }

                        else if (jars[j] > jars[j - 1] && jars[j] > biggestSaleAmount)
                        {
                            biggestSale = salsa[j];
                            biggestSaleAmount = jars[j];
                        }

                        else if (jars[j] < jars[j - 1] && jars[j] > biggestSaleAmount)
                        {
                            smallestSale = salsa[j];
                            biggestSaleAmount = jars[j];
                        }


                }


            // Printing out the best and worst selling salsas
            cout << "salsa that sold the least was " << smallestSale << endl;

            cout << "salsa that sold the most was " << biggestSale << endl;




    return 0;
}
