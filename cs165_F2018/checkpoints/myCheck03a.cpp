/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

int prompt() throw (const char *)
{
   int num;
   
   cout << "Enter a number: ";
   cin  >> num;

   if (num < 0)
      throw "The number cannot be negative.";
   if (num > 100)
      throw "The number cannot be greater than 100.";
   if (num % 2 == 1)
      throw "The number cannot be odd.";

   return num;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int num;
   
   try
   {
      num = prompt();
   }
   catch (const char * message)
   {
      cout << "Error: "
           << message << endl;
      return 0;
   }

   cout << "The number is "
        << num << ".\n";
   
   return 0;
}
