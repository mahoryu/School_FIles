/*****************
 * check08b.cpp
 *****************/

#include "phone.h"
#include "smartphone.h"

#include <iostream>
#include <string>
using namespace std;

/***************************************************
 * Function: main
 * Purpose: Tests a phone and a smart phone object.
 ***************************************************/
int main()
{
   cout << "Phone:\n";

   // TODO: Create your Phone object here and call its promptNumber method
   Phone p1;
   p1.promptNumber();

   cout << "\nPhone info:\n";
   // TODO: Call your Phone's display method here
   p1.display();


   cout << "\nSmart phone:\n";
   
   // TODO: Create your SmartPhone object here and call its prompt method
   SmartPhone p2;
   p2.prompt();
   
   cout << "\nPhone info:\n";
   // TODO: Call your SmartHpone's display method here
   p2.display();


   return 0;
}
