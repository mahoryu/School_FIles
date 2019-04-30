/***********************************************************************
* Program:
*    Checkpoint 03b, Errors
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

int prompt();

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int number = prompt();
   
   cout << "The number is " << number << ".\n";
   
   return 0;
}

int prompt()
{
   int number;
   bool repeat;
   do
   {
      repeat = false;
      cout << "Enter a number: ";
      cin  >> number;

      if (cin.fail())
      {
         cout << "Invalid input.\n";
         cin.clear();
         cin.ignore(256, '\n');
         repeat = true;
      }
   }
   while (repeat);
   
   return number;
}
