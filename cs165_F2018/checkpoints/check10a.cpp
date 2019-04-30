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
#include <string>
#include <vector>
using namespace std;
/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{

   // vector of ints section
   vector <int> iData;
   int num;
   do
   {
      cout << "Enter int: ";
      cin  >> num;
      if (num != 0)
         iData.push_back(num);
   }
   while (num != 0);
   
   cout << "Your list is:\n";

   for (vector <int> :: iterator it = iData.begin(); it != iData.end(); ++it)
      cout << *it << endl;

   cout << endl;
   
   // vector of strings section
   vector <string> sData;
   string word;

   do
   {
      cout << "Enter string: ";
      cin  >> word;
      if (word != "quit")
         sData.push_back(word);
   }
   while (word != "quit");

   cout << "Your list is:\n";

   for (vector <string> :: iterator it = sData.begin(); it != sData.end(); ++it)
      cout << *it << endl;

   return 0;
}


