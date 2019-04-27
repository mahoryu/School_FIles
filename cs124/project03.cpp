/***********************************************************************
* Program:
*    Project 03, Monthly Budget
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program is designed to keep track of the user's monthly
*    budget as well as record what their actual expenses were by
*    asking them to enter in said information.
*
*    Estimated:  2.0 hrs   
*    Actual:     3.25 hrs
*      The most difficult part was rearranging the calculations so that I
*      could have them as separate functions instead of having them all
*      be within main(). I also had trouble figuring out what kind of
*      functions I needed to make them work properly. I tried void at
*      first, but later settled on float.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Here I am listing all functions before main() as prototypes.
float getIncome();
float getBudgetLiving();
float getActualLiving();
float getActualTaxes();
float getActualTithing();
float getActualOther();

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
   
   // Gives instructions for what to input.
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";
   
   // Prompts user to enter required numbers one at a time
   float income = getIncome();
   float budgetLiving = getBudgetLiving();
   float actualLiving = getActualLiving();
   float actualTaxes = getActualTaxes();
   float actualTithing = getActualTithing();
   float actualOther = getActualOther();
   cout << endl;

   // Calculate tithing budget and other budget.
   float budgetTithing = income / 10;
   float budgetTaxes = 0;
   float budgetOther = (income - budgetTaxes - budgetTithing -
                        budgetLiving);
   
   // Calculate differences.
   float budgetDifference =
      (income - budgetTaxes - budgetTithing - budgetLiving
       - budgetOther);
   float actualDifference =
      (income - actualTaxes - actualTithing - actualLiving
       - actualOther); 

   // Explains the output
   cout << "The following is a report on your monthly expenses\n";
   
   // Header
   cout << "\tItem                  Budget          Actual\n"
        << "\t=============== =============== ===============\n";

   // Display categories and numbers
   cout << "\tIncome          $"
        << setw(11) << income
        << "    $"
        << setw(11) << income
        << endl;
   cout << "\tTaxes           $"
        << setw(11) << budgetTaxes       // Will define next week
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


   // Displays the differences
   cout << "\t=============== =============== ===============\n"
        << "\tDifference      $"
        << setw(11) << budgetDifference
        << "    $"
        << setw(11) << actualDifference
        << endl;

   
   return 0;
}

/**********************************************************************
 * Asks for income and returns the value given. 
 ***********************************************************************/
float getIncome()
{
   float income;
   cout << "\tYour monthly income: ";
   cin  >> income;

   return income;
}

/**********************************************************************
 * Asks for the budgeted living expenses and returns the value given.
 ***********************************************************************/
float getBudgetLiving()
{
   float budgetLiving;
   cout << "\tYour budgeted living expenses: ";
   cin  >> budgetLiving;

   return budgetLiving;
}

/**********************************************************************
 * Asks for the actual living expenses and returns the value given.
 ***********************************************************************/
float getActualLiving()
{
   float actualLiving;
   cout << "\tYour actual living expenses: ";
   cin  >> actualLiving;

   return actualLiving;
}


/**********************************************************************
 * Asks for the actual taxes and returns the value given.
 ***********************************************************************/
float getActualTaxes()
{
   float actualTaxes;
   cout << "\tYour actual taxes withheld: ";
   cin  >> actualTaxes;

   return actualTaxes;
}

/**********************************************************************
 * Asks for the actual tithing and returns the value given.
 ***********************************************************************/
float getActualTithing()
{
   float actualTithing;
   cout << "\tYour actual tithe offerings: ";
   cin  >> actualTithing;

   return actualTithing;
}

/**********************************************************************
 * Asks for the actual other expenses and returns the value given.
 ***********************************************************************/
float getActualOther()
{
   float actualOther;
   cout << "\tYour actual other expenses: ";
   cin  >> actualOther;

   return actualOther;
}

