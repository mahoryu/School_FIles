/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*      The most difficult part was figuring out which variables to use
*      for each of the functions, but after watching the video Brother
*      Honeycutt posted at the beginning of the week, it made much more
*      sense to me.
************************************************************************/

#include <iostream>
using namespace std;

// Listing Prototypes
void questionPeter();
int  responseLord();

/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}

/**********************************************************************
* This function will display the question Peter asks Jesus about
* forgiveness.
***********************************************************************/
void questionPeter()
{
   // Display the question
   cout << "Lord, how oft shall my brother sin against me, and I "
        << "forgive him?\nTill seven times?\n";
}

/**********************************************************************
* This function will display the numerical answer Jesus gave to Peter, 
* 7 * 70, or 490.
***********************************************************************/
int responseLord()
{
   // declare the integer's value to display
   int timesToForgive = 7 * 70;

   return timesToForgive;
}
