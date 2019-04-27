/***********************************************************************
* Program:
*    Assignment 34, Character Search in a String
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program prompts the user for a letter and then asks them for a
*    string of text and then returns how many times that letter occurs
*    within the string of text. This time though, it uses the start
*    format instead of the bracket format.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.4 hrs
*      The most difficult part was learning that I had to declare pText
*      in main and not in the countLetters() function and so I had to
*      pass pText to the function instead of text[].
************************************************************************/

#include <iostream>
using namespace std;

int countLetters(char letter, char * pText);

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
   char * pText = &text[256];
   
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
 * many times a letter occurs within the "text" string. This time though,
 * it uses the star format instead of the brackets.
 ***********************************************************************/
int countLetters(char letter, char * pText)
{
   int count = 0;
   for (const char * p = pText; *p; p++)
   {
      if (*p == letter)
         count++;
   }
   return count;
}
