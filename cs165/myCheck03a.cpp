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
using namespace std;

int prompt() throw(const char *);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   try
   {
      int number = prompt();

      cout << "The number is " << number << ".\n";
   }
   catch (const char * message)
   {
      cout << "Error: "
           << message
           << endl;
   }
        
   return 0;
}

int prompt() throw (const char *)
{
   int number;
   cout << "Enter a number: ";
   cin  >> number;

   if(number < 0)
      throw "The number cannot be negative.";
   if (number > 100)
      throw "The number cannot be greater than 100.";
   if (number % 2 == 1)
      throw "The number cannot be odd.";
   
   return number;
}
