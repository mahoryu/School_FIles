/***********************************************************************
* Program:
*    Checkpoint ###, ????          (e.g. Checkpoint 01a, review)  
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <list>
using namespace std;


void promptNumbers(list<int> &data)
{
   int num;

   do
   {
      cout << "Enter a number: ";
      cin  >> num;
      if (num != 0)
         data.push_back(num);
   }
   while (num != 0);
}

void displayNumbers(const list<int> &data)
{
   cout << "Your numbers are:\n";
   
   for (list <int> :: const_reverse_iterator it = data.rbegin(); it != data.rend(); ++it)
   {
      cout << *it << endl;
   }
}

void removeOdd(list<int> &data)
{
   for (list <int> :: iterator it = data.begin(); it != data.end(); /*blank*/)
   {
      if ((*it) % 2 == 1)
         it = data.erase(it);
      else
         ++it;
   }
}

int main()
{
   list <int> data;
   promptNumbers(data);
   cout << endl;
   displayNumbers(data);

   removeOdd(data);
   cout << "Removing odd numbers.....\n";
   displayNumbers(data);
 
   return 0;
}
