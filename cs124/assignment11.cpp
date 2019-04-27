/***********************************************************************
* Program:
*    Assignment 11, Display Monthly Budget
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program will display a monthly budget on the screen in an easy
*    to read format.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.7 hrs
*      The most difficult part about this assignment was figuring out how
*      to use the setw() and which lines required "cout <<" and which ones
*      only needed the "<<"
************************************************************************/

#include <iostream>     // required for cout
#include <iomanip>      // will be using setw() function
using namespace std;

/**********************************************************************
 * Function "main" will display the the monthly budget on the screen in
 * two columns. The left side will have the category and the right
 * will have the dollar amounts.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);         // no scientific notation
   cout.setf(ios::showpoint);     // always show the decimal for real #'s
   cout.precision(2);             // 2 digits for money
   // line 1 (Categories)
   cout << "\tItem           Projected\n";
   // line 2 (Lines)
   cout << "\t=============  ==========\n";
   // line 3 (Income)
   cout << "\tIncome         $";
   cout << setw(9) << 1000.;
   cout << endl;
   // line 4 (Taxes)
   cout << "\tTaxes          $";
   cout << setw(9) << 100.;
   cout << endl;
   // line 5 (Tithing)
   cout << "\tTithing        $";
   cout << setw(9) << 100.;
   cout << endl;
   // line 6 (Living)
   cout << "\tLiving         $";
   cout << setw(9) << 650.;
   cout << endl;
   // line 7 (Other)
   cout << "\tOther          $";
   cout << setw(9) << 90.;
   cout << endl;
   // line 8 (Lines)
   cout << "\t=============  ==========\n";
   // line 9 (Delta)
   cout << "\tDelta          $";
   cout << setw(9) << 60.;
   cout << endl;
   
   return 0;
}
