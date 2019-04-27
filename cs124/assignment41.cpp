/***********************************************************************
* Program:
*    Assignment 41, Memory Prompt
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program asks the user for a number of characters and then
*    allocates that much memory and then stores the phrase that the user
*    is then prompted for and then the program will display those
*    characters back to the user.
*
*    Estimated:  1.5 hrs   
*    Actual:     1.0 hrs
*      The most difficult part was remembering that pText had to be
*      declared in the main() function in order for me to be able to
*      pass it on to other functions.
************************************************************************/

#include <iostream>
using namespace std;

int promptMemory();
bool checkMemory(int numChar, char * pText);
void promptText(int numChar, char * pText);
void displayText(char * pText, int numChar);

/**********************************************************************
 * Function main() prompts the user for the number of characters they
 * want to use, Allocates the memory needed and checks to see if it is
 * valid, stores the text in the array, displays the text back to the
 * user and deletes the NULL pointer.
 ***********************************************************************/
int main()
{
   int numChar = promptMemory();

   char * pText = new(nothrow) char[numChar + 1];
   
   if (checkMemory(numChar, pText) == false)
   {
      cout << "Allocation failure!\n";
      return 0;
   }

   promptText(numChar, pText);
   displayText(pText, numChar);

   // Clear the pointer
   delete [] pText;
   pText = NULL;
   
   return 0;
}


/**********************************************************************
 * Prompts the user for the number of characters.
 ***********************************************************************/
int promptMemory()
{
   int numChar;
   cout << "Number of characters: ";
   cin  >> numChar;

   cin.ignore();
   
   return numChar;
}

/**********************************************************************
 * Makes sure that the memory allocation worked and that the memory is
 * valid.
 ***********************************************************************/
bool checkMemory(int numChar, char * pText)
{
   if (!pText)
      return false;
      
   if (numChar <= 0)
      return false;

   return true;
}

/**********************************************************************
 * Prompts for the text to store.
 ***********************************************************************/
void promptText(int numChar, char * pText)
{
   cout << "Enter Text: ";
   cin.getline(pText, numChar + 1);
}

/**********************************************************************
 * Displays the stored text.
 ***********************************************************************/
void displayText(char * pText, int numChar)
{
   cout << "Text: ";
   
   for (int i = 0; i < numChar; i++)
      cout << *(pText + i);
   cout << endl;
}
