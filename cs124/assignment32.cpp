/***********************************************************************
* Program:
*    Assignment 32, Character Search in a String
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program prompts the user for a letter and then asks them for a
*    string of text and then returns how many times that letter occurs
*    within the string of text.
*
*    Estimated:  1.5 hrs   
*    Actual:     0.3 hrs
*      The most difficult part was understanding where the cin.ignore()
*      was supposed to go within the function main().
************************************************************************/

#include <iostream>
using namespace std;

int countLetters(char letter, char text[]);

/**********************************************************************
 * Function main prompts the user for a letter and a string of text and
 * then uses function countLetters() to display how many times the
 * letter was used in the string.
 ***********************************************************************/
int main()
{
   char letter;
   
   cout << "Enter a letter: ";
   cin  >> letter;

   char text[256];
   
   cout << "Enter text: ";
   cin.ignore();
   cin.getline(text, 256);

   int count = countLetters(letter, text);
   
   cout << "Number of '"
        << letter
        << "'s: "
        << count
        << endl;
   
   return 0;
}

/**********************************************************************
 * This function uses a for loop to search through the string for how
 * many times a letter occurs within the "text" string.
 ***********************************************************************/
int countLetters(char letter, char text[])
{
   int count = 0;
   for (int i = 0; text[i]; i++)
   {
      if (letter == text[i])
         count++;
   }
   return count;
}
