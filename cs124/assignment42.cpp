/***********************************************************************
 * Program:
 *    Assignment 42, Dem Bones
 *    Brother Honeycutt, CS124
 * Author:
 *    Ethan Holden
 * Summary: 
 *    This program will display the words to the song Dem Bones by
 *    using the string class
 *
 *    Estimated:  2.0 hrs   
 *    Actual:     1.0 hrs
 *      The most difficult part was figuring out that I had to set num - 1
 *      for the condition and not just num because I was trying to iterate
 *      it more times than were valid.
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/********************************************************************
 * GENERATE SONG
 * This function will generate one long string that constitutes the
 * complete song "Dem Bones."  Note that the list of bones is provided
 * by the parameter list
 ********************************************************************/
string generateSong(string list[], int num)
{
   string output;
   
   // your code goes here
   for (int i = 0; i < num - 1; i++)
      output += list[0 + i] + " bone connected to the " + list[i + 1]
         + " bone\n";
   
   return output;
}

/**********************************************************************
 * MAIN
 * In this program, MAIN is a driver program.  It will feed to generateSong()
 * the list of bones and get back the complete song as a string.  MAIN will
 * then display the song
 ***********************************************************************/
int main()
{
   string list[9] =
      {
         "toe",
         "foot",
         "leg",
         "knee",
         "hip",
         "back",
         "neck",
         "jaw",
         "head"
      };

   // generate the song
   string song = generateSong(list, 9);

   // display the results
   cout << song;
   
   return 0;
}
