/***********************************************************************
* Program:
*    Assignment 15, Full Tithe Payer
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program will compute if a user is a full tithe payer using
*    the complicated formula provided in the scriptures:
*        And after that, those who have thus been tithed shall 
*        pay one-tenth of all their interest annually; and this 
*        shall be a standard law unto them forever, for my holy 
*        priesthood, saith the Lord.  D&C 119:4
*
*    Estimated:  1.0 hrs   
*    Actual:     0.25 hrs
*      The hardest part was realizing that I didn't need to declare the
*      variables, income and tithe, within the isFullTithePayer
*      function.
************************************************************************/

#include <iostream>
using namespace std;

/*******************************************************
 * isFullTithePayer will take the data the user entered
 * in main() and determines if the values given constitute
 * a full tithe.
 *******************************************************/
bool isFullTithePayer(float income, float tithe)
{
   // will calculate whether the tithe payed if full or not.
   if (income * .1 <= tithe)
      return true;
   else
      return false;
}

/**********************************************************************
 * Main will call isFullTithePayer() and display an appropriate message
 * to the user based on the results
 ***********************************************************************/
int main()
{
   float income;
   float tithe;

   // prompt user for income
   cout << "Income: ";
   cin  >> income;

   // prompt user for tithe
   cout << "Tithe: ";
   cin  >> tithe;

   // give the user his tithing report
   if (isFullTithePayer(income, tithe))
      cout << "You are a full tithe payer.\n";
   else
      cout << "Will a man rob God?  Yet ye have robbed me.\n"
           << "But ye say, Wherein have we robbed thee?\n"
           << "In tithes and offerings.  Malachi 3:8\n";

   return 0;
}
