/**********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program will prompt the user for a month and year (1753 or
*    later) and then displays a visual calendar of the selected month.
*
*    Estimated:  4.0 hrs   
*    Actual:     3.2 hrs
*      The hardest part was getting the verifyLeapYear() function to work
*      properly. I tried having a return statement at the end of each IF
*      statement, but that didn't work out correctly because the function
*      was ending too soon. But when I just assigned it to a variable
*      within the function it worked exactly like I wanted it to.
************************************************************************/

#include <iostream>
using namespace std;

int getMonth();
int getYear();
bool verifyLeapYear(int numYear);
int computeOffset(int numMonth, int numYear);
int computeNumDays(int numMonth, bool isLeapYear);
void getMonthName(int numMonth);
void displayCalendar(int numDays, int offset);

/**********************************************************************
 * Main uses all the functions to first gather the information and then
 * compute the different functions to find the other variables and the
 * uses the display function to output the correct calendar.
 ***********************************************************************/
int main()
{
   // prompt for month and year
   int numMonth = getMonth();
   int numYear = getYear();
   cout << endl;

   // calculate required variables
   bool isLeapYear = verifyLeapYear(numYear);
   int numDays = computeNumDays(numMonth, isLeapYear);
   int offset = computeOffset(numMonth, numYear);

   // display month and calendar
   getMonthName(numMonth);
   cout << ", "
        << numYear
        << endl;
   
   displayCalendar(numDays, offset);
   
   return 0;
}

/**********************************************************************
 * Prompts the user for a month number and keeps prompting until they
 * enter a valid number.
 ***********************************************************************/
int getMonth()
{
   int numMonth;
   
   // prompts for month
   cout << "Enter a month number: ";
   cin  >> numMonth;

   // re-prompts until valid
   while (numMonth < 1 || numMonth > 12)
   {
      cout << "Month must be between 1 and 12.\n";
      cout << "Enter a month number: ";
      cin  >> numMonth;
   }

   return numMonth;
}

/**********************************************************************
 * Prompts the user for a year and keeps prompting until they enter a
 * valid number.
 ***********************************************************************/
int getYear()
{
   int numYear;
   
   // prompts for year
   cout << "Enter year: ";
   cin  >> numYear;


   // re-prompts until valid
   while (numYear < 1753)
   {
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin  >> numYear;
   }

   return numYear;
}

/**********************************************************************
 * Determines whether or not the year entered is a leap year.
 ***********************************************************************/
bool verifyLeapYear(int numYear)
{
   bool isLeapYear = true;
   if (numYear % 4 != 0)             // Year needs to be divisible by 4
      isLeapYear = false;
   else if (numYear % 100 == 0)      // can't be divisible by 100
      isLeapYear = false;
   if (numYear % 400 == 0)           // unless it is divisible by 400
      isLeapYear = true;
   return isLeapYear;
}

/**********************************************************************
 * Determines the offset by taking the year and the month from the input.
 ***********************************************************************/
int computeOffset(int numMonth, int numYear)
{
   int numDaysTotal = 0;

   // adding days to the total by year
   for (int countY = 1753; countY < numYear; countY++)
   {
      if (verifyLeapYear(countY) == false)
         numDaysTotal += 365;
      else
         numDaysTotal += 366;
   }
   // adding days to the total by month
   for (int countM = 1; countM < numMonth; countM++)
      numDaysTotal += computeNumDays(countM, verifyLeapYear(numYear));

   int offset = numDaysTotal % 7;
   
   return offset;
}

/**********************************************************************
 * Takes the inputted month number and  whether or not it is a leap year
 * then determines the number of days in that month.
 ***********************************************************************/
int computeNumDays(int numMonth, bool isLeapYear)
{
   int numDays;
   if (numMonth == 1 || numMonth == 3 || numMonth == 5 || numMonth == 7
       || numMonth == 8 || numMonth == 10 || numMonth == 12)
      numDays = 31;
   else if (numMonth == 4 || numMonth == 6 || numMonth == 9 || numMonth
            == 11)
      numDays = 30;
   else if (isLeapYear == true)
      numDays = 29;
   else
      numDays = 28;
   return numDays;
}

/**********************************************************************
 * Takes the month number and changes it into the calendar month name.
 ***********************************************************************/
void getMonthName(int numMonth)
{
   
   if (numMonth == 1)
      cout << "January";
   else if (numMonth == 2)
      cout << "February";
   else if (numMonth == 3)
      cout << "March";
   else if (numMonth == 4)
      cout << "April";
   else if (numMonth == 5)
      cout << "May";
   else if (numMonth == 6)
      cout << "June";
   else if (numMonth == 7)
      cout << "July";
   else if (numMonth == 8)
      cout << "August";
   else if (numMonth == 9)
      cout << "September";
   else if (numMonth == 10)
      cout << "October";
   else if (numMonth == 11)
      cout << "November";
   else
      cout << "December";
}

/**********************************************************************
 * Takes the number of days and the offset to display a wall style
 * calendar of the selected month.
 ***********************************************************************/
void displayCalendar(int numDays, int offset)
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
         // end line after each Sat except one at end of the month
         if ((day) % 7 == 1 && day != numDays + 1)
            cout << endl;
      }

   // the display for every other offset
   else
   {
      // set the offset
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
