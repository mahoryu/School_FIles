/***********************************************************************
* Program:
*    Assignment 16, Determine Tax Bracket
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program will ask the user for their total taxable income and
*    then determine which tax bracket they are in and give the
*    percentage they will have to pay on taxes.
*     
*    Estimated:  1.0 hrs   
*    Actual:     1.5 hrs
*      The most difficult part was figuring out what I was doing wrong
*      in how I was setting parameters. I was putting computeTax(int
*      income) in not just when I was declaring the functions, but also
*      when I was using the function within main. But all I needed was
*      computeTax(income).
************************************************************************/

#include <iostream>
using namespace std;

int computeTax(int income);

/**********************************************************************
 * Function "main" asks for the user's income and then uses computeTax
 * to display the user's tax bracket.
 ***********************************************************************/
int main()
{
   int income;

   // Asking for income
   cout << "Income: ";
   cin  >> income;

   // Using computeTax function to calculate the tax bracket.
   int taxBracket = computeTax(income);
   
   cout << "Your tax bracket is "
        << taxBracket
        << "%\n";
   
   return 0;
}

/**********************************************************************
 * Function "computeTax" takes the entered income and and calculates
 * the user's tax bracket with the use of IF statements.
 ***********************************************************************/
int computeTax(int income)
{
   if (income <= 15100)
      return 10;
   else if (income <= 61300)
      return 15;
   else if (income <= 123700)
      return 25;
   else if (income <= 188450)
      return 28;
   else if (income <= 336550)
      return 33;
   else
      return 35;
}
