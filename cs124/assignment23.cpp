/***********************************************************************
* Program:
*    Assignment 23, Adding Multiples Under 100
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program will prompt the user to enter a number and give them
*    the sum of all the multiples of that number that are less than 100.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      The most difficult part was making sure I had the syntax right in
*      the FOR loop. I kept doing something wrong where the program would
*      compile but every time I put in a number and pressed ENTER it
*      wouldn't do anything except try to get me to enter more into the
*      program. I am still not sure what went wrong or how I fixed it.
************************************************************************/

#include <iostream>
using namespace std;

int promptNumber();
int calculateSum(int number);
void display(int number, int sum);

/**********************************************************************
 * Function "main" will call on the other functions to ask for a number
 * and then return the sum of all the multiples of that number that are
 * less than 100.
 ***********************************************************************/
int main()
{
   int number = promptNumber();
   int sum = calculateSum(number);

   display(number, sum);
   cout << endl;
   
   return 0;
}

/**********************************************************************
 * Will prompt the user for a number.
 ***********************************************************************/
int promptNumber()
{
   int number;
   cout << "What multiples are we adding? ";
   cin  >> number;

   return number;
}

/**********************************************************************
 * Calculates the sum of the multiples of the entered number.
 ***********************************************************************/
int calculateSum(int number)
{
   int sum = 0;
   for (int multiple = 0; multiple < 100; multiple += number)
      sum = sum + multiple;
   return sum;
}

/**********************************************************************
 * Displays the results.
 ***********************************************************************/
void display(int number, int sum)
{
   cout << "The sum of multiples of "
        << number
        << " less than 100 are: "
        << sum;
}
