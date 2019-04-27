/***********************************************************************
* Program:
*    Project 02, Monthly Budget
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program is designed to keep track of the user's monthly
*    budget as well as record what their actual expenses were by
*    asking them to enter in said information.
*
*    Estimated:  2.0 hrs   
*    Actual:     1.5 hrs
*      The most difficult part was making sure to count the spaces 
*      properly in order to get everything to align correctly. Other
*      than that it wasn't terribly difficult.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Function "main" will prompt the user to enter first their budget for
 * the month and then for what the actual expenses were. Then once
 * finished it will display the information in an easy to read format.
 ***********************************************************************/
int main()
{
   // This will set the numbers entered to be displayed with two
   // decimal points.
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Declaring all variables
   // I put more than needed only so that I was ready to use them
   // later, when we continue with this program.
   float budgetIncome;
   float actualIncome;
   float budgetLiving;
   float actualLiving;
   float budgetTaxes;
   float actualTaxes;
   float budgetTithing;
   float actualTithing;
   float budgetOther;
   float actualOther;
      
   // Gives instructions for what to input.
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";
   
   // Prompts user to enter required numbers one at a time
   cout << "\tYour monthly income: ";
   cin  >> actualIncome;
   cout << "\tYour budgeted living expenses: ";
   cin  >> budgetLiving;
   cout << "\tYour actual living expenses: ";
   cin  >> actualLiving;
   cout << "\tYour actual taxes withheld: ";
   cin  >> actualTaxes;
   cout << "\tYour actual tithe offerings: ";
   cin  >> actualTithing;
   cout << "\tYour actual other expenses: ";
   cin  >> actualOther;
   cout << endl;

   // Explains the output
   cout << "The following is a report on your monthly expenses\n";
   
   // Header
   cout << "\tItem                  Budget          Actual\n"
        << "\t=============== =============== ===============\n";

   // Display categories and numbers
   cout << "\tIncome          $"
        << setw(11) << actualIncome
        << "    $"
        << setw(11) << actualIncome
        << endl;
   cout << "\tTaxes           $"
        << setw(11) << budgetTaxes
        << "    $"
        << setw(11) << actualTaxes
        << endl;
   cout << "\tTithing         $"
        << setw(11) << budgetTithing
        << "    $"
        << setw(11) << actualTithing
        << endl;
   cout << "\tLiving          $"
        << setw(11) << budgetLiving
        << "    $"
        << setw(11) << actualLiving
        << endl;
   cout << "\tOther           $"
        << setw(11) << budgetOther
        << "    $"
        << setw(11) << actualOther
        << endl;

   // Displays the "difference" or rather, it will, once we learn that part
   cout << "\t=============== =============== ===============\n"
        << "\tDifference      $"
        << setw(11) << 0.
        << "    $"
        << setw(11) << 0.
        << endl;
   
   return 0;
}
