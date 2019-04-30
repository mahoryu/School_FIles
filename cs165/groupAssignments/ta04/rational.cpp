/***************************************************************
 * File: rational.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Rational class.
 ***************************************************************/

#include "rational.h"
#include <iostream>
using namespace std;

// put your method bodies here
void Rational :: prompt()
{
   cout << "Top 1: ";
   cin  >> topA;
   cout << "Bottom 1: ";
   cin  >> bottomA;

   cout << "Top 2: ";
   cin  >> topB;
   cout << "Bottom 2: ";
   cin  >> bottomB;

   
}

void Rational :: multiplyBy()
{
   productT = (topA * topB);
   productB = (bottomA * bottomB);
}

void Rational :: display()
{
   if(productT >= productB)
   {
      if (productT % productB == 0)
         cout << productT / productB << endl;
      else
         cout << productT / productB << " "
              << productT % productB << "/"
              << productB << endl;
   }
   else
      cout << productT << "/" << productB << endl;
}

void Rational :: displayDecimal()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
      
   cout << (float)productT / productB << endl;
}
