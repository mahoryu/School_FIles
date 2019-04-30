/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    This program first prompts the user for their own 10 character DNA
*    sequence then asks for how many potential relatives they want to
*    compare DNA with. The program then prompts the user for the names
*    of the potential relatives and then each of their DNA sequences.
*    Then finally the program displays the percentage of how well each
*    potential relative matches the user.
*
*    Estimated:  3.0 hrs   
*    Actual:     3.5 hrs
*      The most difficult part was remembering the syntax for calling on
*      the arrays between functions, but once I figured that out, it went
*      quite smoothly.
************************************************************************/

#include <iostream>
using namespace std;

void promptSelf(char selfDNA[11]);
int promptRelatives(char relNames[][256]);
void promptRelativeDNA(int numRel, char relDNA[][11],
                       char relNames[][256]);
void compareDNA(int numRel, char selfDNA[], char relDNA[][11],
               int percentage[]);
void displayResults(int numRel, char relNames[][256], int percentage[]);

/**********************************************************************
 * Function: main
 * Calls on all the other functions to make the program run correctly.
 ***********************************************************************/
int main()
{

   char selfDNA[11];
   char relNames[51][256];
   char relDNA[51][11];
   int percentage[51];

   promptSelf(selfDNA);
   int numRel = promptRelatives(relNames);
   promptRelativeDNA(numRel, relDNA, relNames);
   compareDNA(numRel, selfDNA, relDNA, percentage);
   displayResults(numRel, relNames, percentage);
   
   return 0;
}

/**********************************************************************
 * Function: promptSelf
 * Prompts the user for their own DNA sequence.
 ***********************************************************************/
void promptSelf(char selfDNA[11])
{
   cout << "Enter your DNA sequence: ";
   cin  >> selfDNA;
   
}


/**********************************************************************
 * Function: promptRelatives
 * Prompts the user for the number of potential relatives and then asks
 * the user for their names.
 ***********************************************************************/
int promptRelatives(char relNames[][256])
{
   int numRel;
   
   cout << "Enter the number of potential relatives: ";
   cin  >> numRel;
   cout << endl;

   for (int i = 0; i < numRel; i++)
   {
      cout << "Please enter the name of relative #"
           << i + 1 << ": ";
      cin  >> relNames[i];
   }
   cout << endl;

   return numRel;
}


/**********************************************************************
 * Function: promptRelativeDNA
 * Prompts the user for the DNA sequences of all the listed potential
 * relatives.
 ***********************************************************************/
void promptRelativeDNA(int numRel, char relDNA[][11],
                       char relNames[][256])
{
   for (int i = 0; i < numRel; i++)
   {
      cout << "Please enter the DNA sequence for "
           << relNames[i] << ": ";
      cin  >> relDNA[i];
   }
   cout << endl;
}

/**********************************************************************
 * Function: compareDNA
 * Makes the calculations of what percentage of the given DNA sequences
 * matches that of the user's
 ***********************************************************************/
void compareDNA(int numRel, char selfDNA[], char relDNA[][11],
               int percentage[])
{
   // Go through each name and sequence
   for (int i = 0; i < numRel; i++)
   {
      // Go through each letter it the sequences
      for (int iCom = 0; iCom < 10; iCom++)
      {
         if (selfDNA[iCom] == relDNA[i][iCom])
            percentage[i] += 10;
      }
   }
}

/**********************************************************************
 * Function: displayResults
 * Displays the results for what percentage of the DNA matched the
 * user's for each potential relative.
 ***********************************************************************/
void displayResults(int numRel, char relNames[][256], int percentage[])
{
   for (int i = 0; i < numRel; i++)
   {
      cout << "Percent match for " << relNames[i] << ": "
           << percentage[i] << "%\n";
   }
}
