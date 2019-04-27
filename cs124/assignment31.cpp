/***********************************************************************
* Program:
*    Assignment 31, Average Grades 2
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program asks the user for 10 grades and then calculates and
*    displays the average grade. It even takes into account that "-1" is
*    an ungraded assignment and will not factor that grade into the
*    average.
*    
*    Estimated:  1.0 hrs   
*    Actual:     0.16 hrs
*      I don't think there was a most difficult part for me on this
*      assignment. I was able to understand this one quite easily.
************************************************************************/

#include <iostream>
using namespace std;

void getGrades(int listGrades[], int numGrades);
void averageGrades(int listGrades[], int numGrades);

/**********************************************************************
 * Function "main" calls on the other two functions in order to execute
 * the program.
 ***********************************************************************/
int main()
{
   int listGrades[10];
   int numGrades = 10;
   getGrades(listGrades, numGrades);

   averageGrades(listGrades, numGrades);
   
   return 0;
}

/**********************************************************************
 * Asks the user for 10 grades one at a time and then enters those
 * grades into the listGrades[] array.
 ***********************************************************************/
void getGrades(int listGrades[], int numGrades)
{
   int num;
   for (int iGrade = 0; iGrade < numGrades; iGrade++)
   {
      num = iGrade + 1;
      cout << "Grade " << num << ": ";
      cin  >> listGrades[iGrade];
   }
}


/**********************************************************************
 * Takes the grades from the listGrades[] array and then computes the
 * average grade and displays it to the user. It also takes into account
 * that "-1" counts as an unassigned grade and does not factor that
 * grade into the average.
 ***********************************************************************/
void averageGrades(int listGrades[], int numGrades)
{
   int sumGrades = 0;
   int nullGrades = 0;
   for (int iGrade = 0; iGrade < numGrades; iGrade++)
   {
      if (listGrades[iGrade] == -1)
         nullGrades++;
      else
         sumGrades += listGrades[iGrade];
   }
   if (nullGrades < numGrades)
   {
      int average = sumGrades / (numGrades - nullGrades);

      cout << "Average Grade: "
           << average
           << "%\n";
   }

   else
      cout << "Average Grade: ---%\n";
   
   return;
}
