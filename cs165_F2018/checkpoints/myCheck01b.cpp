/***********************************************************************
* Program:
*    Checkpoint 01b, Arrays
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

void getSize (int &size);
void getList(int size, int numbers[]);
void displayMultiples(int size, int numbers[]);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int size;
   int numbers[21];

   getSize(size);
   getList(size, numbers);
   displayMultiples(size, numbers);
      
   return 0;
}


/**********************************************************************
 * Function: getSize
 * Purpose: This function prompts the user for the size of the list of
 *          numbers that they want to enter and prevents negative
 *          numbers from being entered.
 ***********************************************************************/
void getSize(int &size)
{
   do
   {
      cout << "Enter the size of the list: ";
      cin  >> size;
   }
   while (size <= 0);
}


/**********************************************************************
 * Function: getList
 * Purpose: This function prompts the user for a list of numbers.
 ***********************************************************************/
void getList(int size, int numbers[])
{
   for (int i = 0; i < size; i++)
   {
      cout << "Enter number for index " << i << ": ";
      cin  >> numbers[i];
   }
   cout << endl;
}


/**********************************************************************
 * Function: displayMultiples
 * Purpose: This function loops through the list of numbers and then
 *          displays the numbers that are divisible by 3.
 ***********************************************************************/
void displayMultiples(int size, int numbers[])
{
   cout << "The following are divisible by 3:\n";
   
   for (int i = 0; i < size; i++)
      if (numbers[i] % 3 == 0)
         cout << numbers[i] << endl;
}
