/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   vector <int> numbers;
   int num = 1;
   for (vector <int> :: iterator it = numbers.begin();
       num != 0; ++it)
   {
      
      cout << "Enter int: ";
      cin  >> num;
      numbers.push_back(num);
   }

   cout <<"Your list is:\n";
   
   for (vector <int> :: iterator it = numbers.begin();
        it != numbers.end(); ++it)
   {
      if (*it != 0)
         cout << *it << endl;
      else
         cout << endl;
   }


   vector <string> strings;
   string text;
   for (vector <string> :: iterator it = strings.begin();
       text != "quit"; ++it)
   {
      
      cout << "Enter string: ";
      cin  >> text;
      strings.push_back(text);
   }

   cout <<"Your list is:\n";
   
   for (vector <string> :: iterator it = strings.begin();
        it != strings.end(); ++it)
   {
      if (*it != "quit")
         cout << *it << endl;
   }

   return 0;
}


