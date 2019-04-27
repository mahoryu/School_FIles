/***********************************************************************
* Program:
*    Assignment 30, Average Grades
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program asks the user for ten different grades and then
*    calculates the average and displays it back to the user.
*    
*    Estimated:  1.5 hrs   
*    Actual:     0.8 hrs
*      The most difficult part was figuring out the exact syntax I
*      needed to pass the array between functions. It wasn't too hard
*      though and just took some trial and error.
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
 * average grade and displays it to the user.
 ***********************************************************************/
void averageGrades(int listGrades[], int numGrades)
{
   int sumGrades = 0;
   for (int iGrade = 0; iGrade < numGrades; iGrade++)
      sumGrades += listGrades[iGrade];

   
   int average = sumGrades / numGrades;

   cout << "Average Grade: "
        << average
        << "%\n";

   return;
}
