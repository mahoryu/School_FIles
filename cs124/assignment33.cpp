/***********************************************************************
* Program:
*    Assignment 33, Dinner Date
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program prompts the user for the account balances of Sam's and
*    Sue's checking accounts as well as the cost of different items that
*    were bought on the date. It then subtracts those costs from the
*    account with the most money and displays the remaining balance of
*    each.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*      The most difficult part was figuring out how many functions this
*      program should be split into and what part of the program should
*      go into each one.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

void date(float * pAccount);

/**********************************************************************
 * Function "main" prompts the user for Sam's and Sue's account balances,
 * assigns the pointer to the one with the higher value, calls on the
 * date() function, and returns the ending balance of each accounts.
 ***********************************************************************/
int main()
{
   float samBalance;
   float sueBalance;
   
   cout << "What is Sam's balance? ";
   cin  >> samBalance;
   cout << "What is Sue's balance? ";
   cin  >> sueBalance;

   // assign pointer to the higher balance
   float * pAccount;
   if (samBalance > sueBalance)
      pAccount = &samBalance;
   else
      pAccount = &sueBalance;

   date(pAccount);

   // set number display to a money format
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << "Sam's balance: $"
        << samBalance << endl;
   cout << "Sue's balance: $"
        << sueBalance << endl;
   
   return 0;
}

/**********************************************************************
 * Prompts the user for the cost of each item on the date and then
 * subtracts each one from the variable the pointer is assigned to.
 ***********************************************************************/
void date(float * pAccount)
{
   float dinner;
   float movie;
   float iceCream;

   // ask for cost and subtract
   cout << "Cost of the date:\n"
        << "\t" << setw(11) << left << "Dinner:";
   cin  >> dinner;
   *pAccount -= dinner;

   // ask for cost and subtract
   cout << "\t" << setw(11) << "Movie:";
   cin  >> movie;
   *pAccount -= movie;
   
   // ask for cost and subtract      
   cout << "\t" << setw(11) << "Ice cream:";
   cin  >> iceCream;
   *pAccount -= iceCream;

   return;
}
