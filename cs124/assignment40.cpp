/***********************************************************************
* Program:
*    Assignment 40, Tic-Tac-Toe Board
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program reads a Tic-Tac-Toe file and then displays it within a
*    chart for the user and then asks the user for a new file name to
*    write the array into the named file.
*
*    Estimated:  2.0 hrs   
*    Actual:     1.5 hrs
*      I didn't really think of any part as terribly difficult. I just
*      had to remember to convert the '.' into ' ', but that really
*      wasn't too hard to do.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

bool readFile(char fileNameIn[], char table[][3]);
void displayTable(char table[][3]);
bool writeFile(char table[][3], char fileNameOut[]);

/**********************************************************************
 * Prompts the user for a file, reads the file to an array, displays a
 * table based on the array, and writes the array to a new file defined
 * by the user.
 ***********************************************************************/
int main()
{
   char fileNameIn[256];
   char table[3][3];
   char fileNameOut[256];

   //Prompt for file
   cout << "Enter source filename: ";
   cin  >> fileNameIn;

   if (readFile(fileNameIn, table) == false)
   {
      cout << "Unable to open file "
           << fileNameIn << endl;
      return 0;
   }

   // Display
   displayTable(table);

   // Write new file
   cout << "Enter destination filename: ";
   cin  >> fileNameOut;

   if (writeFile(table, fileNameOut) == false)
   {
      cout << "Unable to write to file "
           << fileNameOut << endl;
      return 0;
   }
   else
      cout << "File written\n";
   
   return 0;
}

/**********************************************************************
 * This function reads the file and then converts the file into a usable
 * array.
 ***********************************************************************/
bool readFile(char fileNameIn[], char table[][3])
{
   ifstream fin(fileNameIn);
   if (fin.fail())
   {
      fin.close();
      return false;
   }

   // Read file into array.
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         fin >> table[row][col];
   fin.close();
   
   // Convert '.' to ' '
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         table[row][col] = (table[row][col] == '.' ?
                             ' ' : table[row][col]);

   return true;

}

/**********************************************************************
 * Takes the array and displays it in a user friendly format.
 ***********************************************************************/
void displayTable(char table[][3])
{
   cout << " ";

   // Reads the array one item at a time
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         // Display changes based on which column it is working on
         switch (col)
         {
            case 0:
               cout << table[row][col]
                    << " | ";
               break;
            case 1:
               cout << table[row][col]
                    << " | ";
               break;
            case 2:
               // checks to see if it is on the last row so we
               //    can end the display table properly
               if (row != 2)
               {
                  cout << table[row][col]
                       << " \n"
                       << "---+---+---\n ";
               }
               else
               {
                  cout << table[row][col]
                       << " \n";
               }
               break;
         }
}

/**********************************************************************
 * Takes the array and writes it to a new file as defined by the user.
 ***********************************************************************/
bool writeFile(char table[][3], char fileNameOut[])
{
   ofstream fout(fileNameOut);
   if (fout.fail())
   {
      fout.close();
      return false;
   }

   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         // Writes the file and converts ' ' back to '.'
         fout << (table[row][col] == ' ' ? '.' : table[row][col])
              << (col == 2 ? '\n' : ' ');
   
   fout.close();
   return true;
}
