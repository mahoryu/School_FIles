/***********************************************************************
* Program:
*    Assignment 13, Fahrenheit to Celsius
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program will ask the user for a temperature in Fahrenheit and
*    then display what that temperature would be in Celsius.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.75 hrs
*      The hardest part for me was getting the Celsius output to not
*      display the decimal point on all the numbers. My problem was that
*      I had used cout.setf(ios::showpoint) without even thinking about
*      how that was the problem. So when I deleted that line, the problem
*      was fixed.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function "main" first asks for a temperature in Fahrenheit, converts
 * it to Celsius, and then displays the result.
 ***********************************************************************/
int main()
{
   // Sets the number of decimal places to zero.
   cout.setf(ios::fixed);
   cout.precision(0);

   // Declaring variable f.
   float f;

   // Asking for Fahrenheit
   cout << "Please enter Fahrenheit degrees: ";
   cin  >> f;

   //conversions of Fahrenheit to Celsius
   float c = 5.0 / 9.0 * (f - 32);

   // Display the converted Celsius output.
   cout << "Celsius: " << c << endl;
   
   return 0;
}
