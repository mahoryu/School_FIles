/***********************************************************************
* Program:
*    Assignment 35, Number Grade to Letter Grade
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program asks the the user for a number grade and then return
*    the associated letter grade with its accompanying symbol if it has
*    one.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.75 hrs
*      The most difficult part was trying to get the conditional
*      expressions to compile correctly.
************************************************************************/

#include <iostream>
using namespace std;

char computeGradeSign(int numGrade);
char computeLetterGrade(int numGrade);

/**********************************************************************
 * Function main() prompts the user for a grade number and then calls on
 * the other functions for calculations and then returns the letter grade
 * and sign associated with that grade.
 ***********************************************************************/
int main()
{
   int numGrade;
   
   cout << "Enter number grade: ";
   cin  >> numGrade;

   char letterGrade = computeLetterGrade(numGrade);
   char gradeSign = computeGradeSign(numGrade);

   cout << numGrade << "% is "
        << letterGrade;

   if (gradeSign != '*')
   {
      cout << gradeSign;
   }
   cout << endl;
      
   return 0;
}


/**********************************************************************
 * This function uses a SWITCH statement in order determine the letter of
 * the grade the user entered.
 ***********************************************************************/
char computeLetterGrade(int numGrade)
{
   char letterGrade;
   switch (numGrade / 10)
   {
      case 10:
      case 9:
         letterGrade = 'A';
         break;
      case 8:
         letterGrade = 'B';
         break;
      case 7:
         letterGrade = 'C';
         break;
      case 6:
         letterGrade = 'D';
         break;
      default:                      // Cases 0 through 5
         letterGrade = 'F';
         break;
        
   }

   return letterGrade;
}


/**********************************************************************
 * This function takes the grade and determines if and what sign will go
 * with the letter.
 ***********************************************************************/
char computeGradeSign(int numGrade)
{
   char gradeSign;
   switch (numGrade % 10)
   {
      case 9:
      case 8:
      case 7:
         gradeSign = '+';
         break;
      case 0:
      case 1:
      case 2:
         gradeSign = '-';
         break;
      default:                // Cases 3 through 6
         gradeSign = '*';
         break;
   }

   // No + for an A
   gradeSign = (numGrade >= 90 ? '*' : gradeSign);
   // No = or - for an F
   gradeSign = (numGrade < 60 ? '*' : gradeSign);
   
   return gradeSign;
}
