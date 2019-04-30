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
#include <vector>
using namespace std;


void promptNumbers(vector<int> &data)
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

void displayNumbers(vector<int> &data)
{
   cout << "Your numbers are:\n";
   
   for (vector <int> :: iterator it = data.begin(); it != data.end(); ++it)
   {
      cout << *it << endl;
   }
}

void removeOdd(vector<int> &data)
{
   for (vector <int> :: iterator it = data.begin(); it != data.end(); /*blank*/)
   {
      if ((*it) % 2 == 1)
         it = data.erase(it);
      else
         ++it;
   }
}

int main()
{
   vector <int> data;
   promptNumbers(data);
   cout << endl;
   displayNumbers(data);

   removeOdd(data);
   cout << "Removing odd numbers.....\n";
   displayNumbers(data);
   
   return 0;
}
