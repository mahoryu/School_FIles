/***********************************************************************
* Program:
*    Assignment 12, Input and Output Monthly Income
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program will prompt the user to input their monthly income
*    and then display what their income is back to them.
*
*    Estimated:  0.7 hrs   
*    Actual:     0.5 hrs
*      The most difficult part was remembering to use #include <iomanip>
*      in order to get setw() to work properly.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Function "main" asks the user for their income and then displays
 * it back to them as a floating number.
 ***********************************************************************/
int main()
{
   // Ask user for income
   float income;
   cout << "\tYour monthly income: ";
   cin >> income;

   // Set numbers to two decimal places
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Display the income
   cout << "Your income is: $"
        << setw(9) << income
        << endl;  
   return 0;
}
