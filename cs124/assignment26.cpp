/***********************************************************************
* Program:
*    Assignment 26, Average Grades from File
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program asks the user for a file with ten grades in it and then
*    calculates the average grade. It also displays errors if something
*    is wrong with the file or if not exactly ten grades in the file.
*
*    Estimated:  2.0 hrs   
*    Actual:     1.5 hrs
*      The most difficult part was figuring out how to call the
*      functions within the main() function. Once I figured that out, I
*      was able to get everything to work.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void getFileName(char fileName[]);
float readFile(char fileName[]);
void display(float average);

/**********************************************************************
 * Takes the functions and puts them together to display the average of
 * the grades within the file that the user selected.
 ***********************************************************************/
int main()
{
   char fileName[256];
   getFileName(fileName);

   float average = readFile(fileName);

   display(average);
   
   return 0;
}


/**********************************************************************
 * Prompts the user for a file name.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin  >> fileName;
   return;
}


/**********************************************************************
 * Calculates the average grade and returns errors if something didn't
 * go right.
 ***********************************************************************/
float readFile(char fileName[])
{
   // Error for if the file didn't exist.
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file \""
           << fileName << "\"\n";
      return false;
   }

   float grade;
   int count = 0;
   float sum = 0;
   float average;

   // Add all the grades together and set a counter
   while (fin >> grade)
   {
      sum += grade;
      count++;
   }
   
   fin.close();

   // Error for if the number of files is not 10
   if (count != 10)
   {
      cout << "Error reading file \""
           << fileName << "\"\n";
      return false;
   }
   // Computes average if all goes well
   else
   {
      average = sum / 10;
      return average;
   }
}


/**********************************************************************
 * This function displays the average grade, but only if the file was
 * valid and there was no error in reading the file.
 ***********************************************************************/
void display(float average)
{
   cout.setf(ios::fixed);
   cout.precision(0);

   if (average != false)
   {
      cout << "Average Grade: "
           << average
           << "%\n";
   }
   return;
}
