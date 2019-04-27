/***********************************************************************
* Program:
*    Assignment 43, Feet to Meters Via Command Line
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program takes the numbers entered as command line parameters
*    and converts them from feet to meters.
*
*    Estimated:  1.5 hrs   
*    Actual:     0.1 hrs
*      This one actually wasn't that difficult at all. The whole thing
*      seemed pretty self explanatory to me.
************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * Function main() takes the numbers entered from the command line,
 * converts them to floating point numbers and then displays the numbers
 * as both feet and what the equivalent would be in meters.
 ***********************************************************************/
int main(int argc, char ** argv)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
      
   float feet;
   float meters;

   // Displaying text for each parameter given in the command line.
   for (int iArg = 1; iArg < argc; iArg++)
   {
      feet = atof(argv[iArg]);
      meters = feet * 0.3048;
      cout << feet
           << " feet is "
           << meters
           << " meters\n";
   }
      
   return 0;
}
