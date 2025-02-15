/***********************************************************************
* Program:
*    Assignment 44, Search Speed
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program compares the search speed of the linear search
*    and the binary search.
*
*    Estimated:  1.5 hrs   
*    Actual:     0.75 hrs
*      The most difficult part was figuring out why testBed number 4
*      wouldn't work. I was getting 500 and not 499.5, but every other
*      testBed came out correctly. I figured out that I needed 'i < num'
*      not 'list[i]' on lines 112 and 139.
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int readNumbers(int list[], int max);
float computeAverageLinear(int list[], int num);
float computeAverageBinary(int list[], int num);
int linear(int list[], int num, int search);
int binary(int list[], int num, int search);

/**********************************************************************
* main reads the list, determines the speed of the searches, and outputs
* the results.
***********************************************************************/
int main()
{
   int list[1024];
   const int MAX = sizeof (list) / sizeof (list[0]);
   int num;

   // read the numbers
   if (!(num = readNumbers(list, MAX)))
      return 1;

   // determine how long it takes for a linear search
   float averageLinear;
   averageLinear = computeAverageLinear(list, num);

   // determine how long it takes for a binary search
   float averageBinary;
   averageBinary = computeAverageBinary(list, num);

   // display results
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   cout << "Linear search: " << setw(10) << averageLinear << endl;
   cout << "Binary search: " << setw(10) << averageBinary << endl;

   return 0;
}

/************************************************************
 * READ NUMBERS
 * Input:
 *    list:    a list of numbers to search through
 *    max:     the size of the numbers list
 * Output:
 *    num:     the number of items actually read
 ***********************************************************/
int readNumbers(int list[], int max)
{
   char fileName[256];
   int  num = 0;

   // get the filename
   cout << "Enter filename of list: ";
   cin  >> fileName;

   // open the file
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Unable to open file " << fileName << endl;
      return 0;
   }

   // read the file
   while (num < max && fin >> list[num])
      num++;

   // make like a tree
   fin.close();
   return num;
}

/*********************************************************
 * COMPUTE AVERAGE LINEAR
 * Input:
 *    list:    a list of numbers to search through
 *    num:     the size of the numbers list
 * Output:
 *    averageLinear: the average number of comparisons it takes
 *                   to find each item in the array
 *******************************************************/
float computeAverageLinear(int list[], int num)
{
   float averageLinear = 0.0;
   float numNumbers = 0.0;

   // put your code here, probably including a collections of
   // calls to linear()
   for (int i = 0; i < num; i++)
   {
      averageLinear += linear(list, num, list[i]);
      numNumbers++;
   }

   averageLinear /= numNumbers;

   return averageLinear;
}

/*********************************************************
 * COMPUTE AVERAGE BINARY
 * Input:
 *    list:    a list of numbers to search through
 *    num:    the size of the numbers list
 * Output:
 *    averageBinary: the average number of comparisons it takes
 *                   to find each item in the array
 *******************************************************/
float computeAverageBinary(int list[], int num)
{
   float averageBinary = 0.0;
   float numNumbers = 0.0;

   // put your code here, probably including a collections of
   // calls to binary()
   for (int i = 0; i < num; i++)
   {
      averageBinary += binary(list, num, list[i]);
      numNumbers++;
   }
      
   averageBinary /= numNumbers;

   return averageBinary;
}

/*******************************************************
 * LINEAR
 * Input:
 *    list:    a list of numbers to search through
 *    num:     the size of the numbers list
 *    search:  the number that you are searching for
 * Output:
 *    compares: the number of compares that were made
 *              before 'search' was found in the 'numbers' array
 ******************************************************/
int linear(int list[], int num, int search)
{
   bool found = false;
   float  compares = 0.0;  // you will need to compute this

   for (int i = 0; i < num && ! found; i++)
   {
      if (search == list[i])
         found = true;
      compares++;
   }

   return compares;
}

/*******************************************************
 * BINARY
 * Input:
 *    list:    a list of numbers to search through
 *    num:     the size of the numbers list
 *    search:  the number that you are searching for
 * Output:
 *    compares: the number of compares that were made
 *              before 'search' was found in the 'numbers' array
 ******************************************************/
int binary(int list[], int num, int search)
{
   bool found = false;
   int  compares = 0;  // you will need to compute this

   // set the bounds of the search space, initially the whole list
   int iFirst = 0;
   int iLast = num - 1;

   // continue until found or the search size is not zero
   while (iLast >= iFirst && !found)
   {
      int iMiddle = (iLast + iFirst) / 2;

      // note that both the == and > count as one comparison
      if (list[iMiddle] == search)
         found = true;
      else if (list[iMiddle] > search)
         iLast = iMiddle - 1;
      else
         iFirst = iMiddle + 1;
      compares++;
   }

   return compares;
}
