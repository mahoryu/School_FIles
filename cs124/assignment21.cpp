/***********************************************************************
* Program:
*    Assignment 21, Stub Program
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This is a Stub program that doesn't actually do anything, except
*    print "Success", but rather makes sure that the functions are
*    calling on each other properly so that debugging will be made
*    easier later.
*
*    Estimated:  1.5 hrs   
*    Actual:     1.75 hrs
*      The most difficult part was realizing that I was doing things
*      right at first, but I had the functions in the wrong order
*      without declaring a prototype for each one, so I ended up with
*      each of them not working because it was looking for functions
*      that were not yet declared at the time.
************************************************************************/

#include <iostream>
using namespace std;

//prompt Periodic
int promptDeValue()
{
   return 0;
}

int promptInsurance()
{
   return 0;
}

int promptParking()
{
   return 0;
}

int getPeriodicCost(int costDeValue, int costInsurance, int costParking)
{
   return 0;
}

//prompt Usage
int promptMileage()
{
   return 0;
}

int promptGas()
{
   return 0;
}

int promptRepairs()
{
   return 0;
}

int promptTires()
{
   return 0;
}

int getUsageCost(int mileage, int costGas, int costRepairs,
                 int costTires)
{
   return 0;
}

//display
void display(int costPeriodic, int costUsage)
{
   cout << "Success\n";
}


//main
int main()
{
   display(getPeriodicCost(promptDeValue(), promptInsurance(),
                           promptParking()),
           getUsageCost(promptMileage(), promptGas(), promptRepairs(),
                        promptTires()));
   return 0;
}
