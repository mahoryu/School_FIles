/***********************************************************************
* Program:
*    Assignment 25, Display Table Function
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program is designed to test out the displayTable function for
*    the calendar project by getting user input in order to get the data
*    that the rest of the calendar program would have already supplied.
*
*    Estimated:  2.0 hrs   
*    Actual:     3.0 hrs
*      The most difficult part, was figuring out how to get the function
*      to display it according to the exact spacing that the testBed
*      wanted, and then getting rid of that extra end line when the month
*      ended on a Saturday.
************************************************************************/

#include <iostream>
using namespace std;

void displayTable(int numDays, int offset);

/**********************************************************************
 * Function "main" will prompt the user for the number of days in the 
 * month and the offset in order to test the "displayTable" function to
 * make sure it works properly.
 ***********************************************************************/
int main()
{
   int numDays;
   int offset;
   
   cout << "Number of days: ";
   cin  >> numDays;

   cout << "Offset: ";
   cin  >> offset;

   displayTable(numDays, offset);
   
   return 0;
}

/**********************************************************************
 * This function takes the data from numDays and offset to adjust the
 * calendar to put the numbers in the correct places on the output.
 ***********************************************************************/
void displayTable(int numDays, int offset)
{
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   int count = 0;
   int day = 1;

   // the display function for when offset is 6 (starts on Sunday)
   if (offset == 6)
      while (day <= numDays)
      {
         // extra space if < 10 since the tab function doesn't work
         if (day < 10)
         {
            cout << "   " << day;
            day++;
         }
         // display for numbers > 10
         else
         {
            cout << "  " << day;
            day++;
         }
         // end the line after each Saturday
         if ((day) % 7 == 1 && day != numDays + 1)
            cout << endl;
      }

   // the display for every other offset
   else
   {
      // set empty spaces
      offset++;
      do
      {
         cout << "    ";
         count++;
      }
      while (count < offset);

      // display the day numbers
      while (day <= numDays)
      {
         // extra space for numbers < 10
         if (day < 10)
         {
            cout << "   " << day;
            day++;
         }
         // display for numbers > 10
         else
         {
            cout << "  " << day;
            day++;
         }
         // end line each Sat except the one at the end of the month
         if ((day + offset) % 7 == 1 && day != numDays + 1)
            cout << endl;
      }
   }
   cout << endl;
}
