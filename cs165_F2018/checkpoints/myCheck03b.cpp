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

int prompt() throw (const char *)
{
   int num;
   cout << "Enter a number: ";
   cin  >> num;
   
   if(cin.fail())
   {
      cin.clear();
      cin.ignore(256,'\n');
      throw "Invalid input.\n";
   }

   return num;
}

void display(int num)
{
   cout << "The number is "
        << num << ".\n";
}

int main()
{
   int num;
   bool end = false;
   while(!end)
   {
      try
      {
         num = prompt();
         end = true;
      }
      catch (const char * message)
      {
         cout << message;
         end = false;
      }
   }
      
   display(num);
   
   return 0;
}
