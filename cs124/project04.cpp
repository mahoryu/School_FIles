/***********************************************************************
* Program:
*    Project 04, Monthly Budget
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program is designed to keep track of the user's monthly
*    budget as well as record what their actual expenses were by
*    asking them to enter in said information.
*
*    Estimated:  2.0 hrs   
*    Actual:     2.8 hrs
*      The most difficult part was something I tried to do on my own
*      initiative. I tried to compress the six functions:
*      getMonthlyIncome() through getActualOther() into one function.
*      I got it to work, all except I kept getting a 0.00 at the end
*      because I tried to use it as a double function and it was trying
*      to return something. I also tried a void function but that didn't
*      work either because I had cin within the function. So I finally
*      decided to just put it back to the way I had it at last week with
*      six different functions.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// List prototypes.
double getMonthlyIncome();
double getBudgetLiving();
double getActualLiving();
double getActualTaxes();
double getActualTithing();
double getActualOther();
double getBudgetTithing(double monthlyIncome);
double getBudgetTaxes(double monthlyIncome);
double getBudgetOther(double monthlyIncome, double budgetTaxes, double
                      budgetTithing, double budgetLiving);
double calculateActualDifference(double monthlyIncome, double
                                 actualTaxes, double actualTithing,
                                 double actualLiving, double actualOther);
double calculateBudgetDifference(double monthlyIncome, double
                                 budgetTaxes, double budgetTithing,
                                 double budgetLiving, double budgetOther);
void displayResults(double monthlyIncome, double budgetTaxes, double
                    actualTaxes, double budgetTithing, double
                    actualTithing, double budgetLiving, double
                    actualLiving, double budgetOther, double
                    actualOther, double budgetDifference, double
                    actualDifference);

/**********************************************************************
 * Function "main" will prompt the user to enter first their budget for
 * the month and then for what the actual expenses were. Then once
 * finished it will display the information in an easy to read format.
 ***********************************************************************/
int main()
{
   // Gives instructions for what to input.
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";
   
   // Prompts user to enter required numbers one at a time
   double monthlyIncome = getMonthlyIncome();
   double budgetLiving = getBudgetLiving();
   double actualLiving = getActualLiving();
   double actualTaxes = getActualTaxes();
   double actualTithing = getActualTithing();
   double actualOther = getActualOther();
   cout << endl;
   
   // Calculate tithing budget, tax budget, and other budget.
   double budgetTithing = getBudgetTithing(monthlyIncome);
   double budgetTaxes = getBudgetTaxes(monthlyIncome);
   double budgetOther = getBudgetOther(monthlyIncome, budgetTaxes,
                                       budgetTithing, budgetLiving);

   // Calculate differences
   double budgetDifference = calculateBudgetDifference(monthlyIncome,
                                                       budgetTaxes,
                                                       budgetTithing,
                                                       budgetLiving,
                                                       budgetOther);
   double actualDifference = calculateActualDifference(monthlyIncome,
                                                       actualTaxes,
                                                       actualTithing,
                                                       actualLiving,
                                                       actualOther);
   
   // Display the table with results
   displayResults(monthlyIncome, budgetTaxes, actualTaxes,
                          budgetTithing, actualTithing, budgetLiving,
                          actualLiving, budgetOther, actualOther,
                          budgetDifference, actualDifference);
   
   return 0;
}

/**********************************************************************
 * Asks for income and returns the value given. 
 ***********************************************************************/
double getMonthlyIncome()
{
   double monthlyIncome;
   cout << "\tYour monthly income: ";
   cin  >> monthlyIncome;

   return monthlyIncome;
}

/**********************************************************************
 * Asks for the budgeted living expenses and returns the value given.
 ***********************************************************************/
double getBudgetLiving()
{
   double budgetLiving;
   cout << "\tYour budgeted living expenses: ";
   cin  >> budgetLiving;

   return budgetLiving;
}

/**********************************************************************
 * Asks for the actual living expenses and returns the value given.
 ***********************************************************************/
double getActualLiving()
{
   double actualLiving;
   cout << "\tYour actual living expenses: ";
   cin  >> actualLiving;

   return actualLiving;
}


/**********************************************************************
 * Asks for the actual taxes and returns the value given.
 ***********************************************************************/
double getActualTaxes()
{
   double actualTaxes;
   cout << "\tYour actual taxes withheld: ";
   cin  >> actualTaxes;

   return actualTaxes;
}

/**********************************************************************
 * Asks for the actual tithing and returns the value given.
 ***********************************************************************/
double getActualTithing()
{
   double actualTithing;
   cout << "\tYour actual tithe offerings: ";
   cin  >> actualTithing;

   return actualTithing;
}

/**********************************************************************
 * Asks for the actual other expenses and returns the value given.
 ***********************************************************************/
double getActualOther()
{
   double actualOther;
   cout << "\tYour actual other expenses: ";
   cin  >> actualOther;

   return actualOther;
}

/**********************************************************************
 * Computes the amount of Tithing the user should be paying.
 ***********************************************************************/
double getBudgetTithing(double monthlyIncome)
{
   double budgetTithing = monthlyIncome / 10;
   return budgetTithing;
}

/**********************************************************************
 * Computes the tax bracket and then how much taxes the user will pay
 ***********************************************************************/
double getBudgetTaxes(double monthlyIncome)
{
   double yearlyTax;
   double yearlyIncome = monthlyIncome * 12;
   
   if (yearlyIncome > 0 && yearlyIncome <= 15100)
      yearlyTax = yearlyIncome * 0.1;
   else if (yearlyIncome <= 61300)
      yearlyTax = 1510 + .15 * (yearlyIncome - 15100);
   else if (yearlyIncome <= 123700)
      yearlyTax = 8440 + .25 * (yearlyIncome - 61300);
   else if (yearlyIncome <= 188450)
      yearlyTax = 24040 + .28 * (yearlyIncome - 123700);
   else if (yearlyIncome <= 336550)
      yearlyTax = 42170 + .33 * (yearlyIncome - 188450);
   else 
      yearlyTax = 91043 + .35 * (yearlyIncome - 336550);

   double monthlyTax = yearlyTax / 12;

   return monthlyTax;
}

/**********************************************************************
 * Calculates how much is left over from the budget numbers and places
 * the difference under the Budget: Other section.
 ***********************************************************************/
double getBudgetOther(double monthlyIncome, double budgetTaxes, double
                      budgetTithing, double budgetLiving)
{
   double budgetOther = (monthlyIncome - budgetTaxes - budgetTithing -
                        budgetLiving);
   return budgetOther;
}

/**********************************************************************
 * Calculates the difference between the income and expenses of the
 * budget column.
 ***********************************************************************/
double calculateBudgetDifference(double monthlyIncome, double
                                 budgetTaxes, double budgetTithing,
                                 double budgetLiving, double budgetOther)
{
   double budgetDifference =
      (monthlyIncome - budgetTaxes - budgetTithing - budgetLiving
       - budgetOther);
   return budgetDifference;
}

/**********************************************************************
 * Calculates the difference between the income and expenses of the
 * actual column.
 ***********************************************************************/
double calculateActualDifference(double monthlyIncome, double
                                 actualTaxes, double actualTithing,
                                 double actualLiving, double actualOther)
{
   double actualDifference =
      (monthlyIncome  - actualTaxes - actualTithing - actualLiving
       - actualOther);
   return actualDifference;
}

/**********************************************************************
 * Gathers all inputted and calculated data and displays the results.
 ***********************************************************************/
void displayResults(double monthlyIncome, double budgetTaxes, double
                    actualTaxes, double budgetTithing, double
                    actualTithing, double budgetLiving, double
                    actualLiving, double budgetOther, double
                    actualOther, double budgetDifference, double
                    actualDifference)
{
   // Setting the number of decimal places to two for units of money 
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   // Explains the output
   cout << "The following is a report on your monthly expenses\n";
   
   // Header
   cout << "\tItem                  Budget          Actual\n"
        << "\t=============== =============== ===============\n";

   // Display categories and numbers
   cout << "\tIncome          $"
        << setw(11) << monthlyIncome
        << "    $"
        << setw(11) << monthlyIncome
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


   // Displays the differences
   cout << "\t=============== =============== ===============\n"
        << "\tDifference      $"
        << setw(11) << budgetDifference
        << "    $"
        << setw(11) << actualDifference
        << endl;
}
