/***********************************************************************
* Program:
*    Project 12, Sudoku
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program allows the user to play a game of sudoku from a file,
*    allows the user to edit the board with the user's answers, and
*    finally saves their game to a new file when they quit the program.
*
*    Estimated:  3.5 hrs   
*    Actual:     3.1 hrs
*      The most difficult part was trying to figure out how to write a
*      new number to the array when the user entered the new value. It
*      turns out that I was having issues with the variable types and
*      didn't assign the correct ones for the program to function.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void readFile(char board[][9]);
void displayOptions();
void displayBoard(char board[][9]);
void editSquare(char board[][9]);
void saveAndQuit(char board[][9]);

/**********************************************************************
 * This function calls on the others to first prompt for and read a file,
 * then displays the board and prompts the user for the various options
 * in order to play the game or to save and exit the program.
 ***********************************************************************/
int main()
{
   char board[9][9];

   //Prompt for file
   readFile(board);

   // Display for first time.
   displayOptions();
   cout << endl;
   displayBoard(board);
   cout << endl;

   // Interaction with the user
   char entry;
   do 
   {
      cout << "> ";
      cin  >> entry;

      if (islower(entry))
         entry = toupper(entry);
   
      switch (entry)
      {
         case '?':
            displayOptions();
            cout << endl;
            break;
         case 'D':
            displayBoard(board);
            break;
         case 'E':
            editSquare(board);
            break;
         case 'S':
            break;
         case 'Q':
            saveAndQuit(board);
            break;
      }
      if (entry != 'Q')
         cout << endl;
   }
   while (entry != 'Q');
   
   return 0;
}


/**********************************************************************
 * Prompts the user for a file, and then reads it into an array that is
 * usable to the program.
 ***********************************************************************/
void readFile(char board[][9])
{
   char fileNameIn[256];
      
   cout << "Where is your board located? ";
   cin  >> fileNameIn;

   ifstream fin(fileNameIn);
   if (fin.fail())
   {
      fin.close();
      cout << "Unable to open file "
           << fileNameIn << endl;
   }
   else
   {
      // Read file into array.
      for (int row = 0; row < 9; row++)
         for (int col = 0; col < 9; col++)
            fin >> board[row][col];
      fin.close();
   
      // Convert '0' to ' '
      for (int row = 0; row < 9; row++)
         for (int col = 0; col < 9; col++)
            board[row][col] = (board[row][col] == '0' ?
                               ' ' : board[row][col]);
   }
}


/**********************************************************************
 * Displays the available options.
 ***********************************************************************/
void displayOptions()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n";
}


/**********************************************************************
 * Displays the current Sudoku board.
 ***********************************************************************/
void displayBoard(char board[][9])
{
   int rowNum = 0;
   
   cout << "   A B C D E F G H I\n";

   for (int row = 0; row < 9; row++)
   {
      // Non-divider rows   
      cout << ++rowNum << "  ";
      for (int col = 0; col < 9; col++)
      {
         switch (col)
         {
            default:
               cout << board[row][col] << " ";
               break;
            case 2:
            case 5:
               cout << board[row][col] << "|";
               break;
            case 8:
               cout << board[row][col] << endl;
               break;
         }
      }
      
      // Divider rows   
      if (row == 2 || row == 5)
         cout << "   -----+-----+-----\n";
   }      
}


/**********************************************************************
 * Empty for now, just saving a spot for next week's project.
 ***********************************************************************/
void computeValues()
{
   
}


/**********************************************************************
 * Takes an input from the user for a desired square and then prompts the
 * user for the new value and enters it into the board.
 ***********************************************************************/
void editSquare(char board[][9])
{
   char letter;
   int number;
   int row;
   int col;
   char newVal;
   
   cout << "What are the coordinates of the square: ";
   cin  >> letter >> number;

   // Change to uppercase if needed
   if (islower(letter))
      letter = toupper(letter);

   // Assign coordinates to row and column
   row = (number - 1);
   switch (letter)
   {
      case 'A':
         col = 0;
         break;
      case 'B':
         col = 1;
         break;
      case 'C':
         col = 2;
         break;
      case 'D':
         col = 3;
         break;
      case 'E':
         col = 4;
         break;
      case 'F':
         col = 5;
         break;
      case 'G':
         col = 6;
         break;
      case 'H':
         col = 7;
         break;
      case 'I':
         col = 8;
         break;
   }

   // Error to keep from writing over a filled square
   if (board[row][col] != ' ')
      cout << "ERROR: Square '"
           << letter << number
           << "' is filled\n";
   else
   {
      // Assigning a new value
      cout << "What is the value at '"
           << letter << number
           << "': ";
      cin  >> newVal;

      board[row][col] = newVal;
   }
}


/**********************************************************************
 * Takes the current board state and writes it to a new file as dictated
 * by the user.
 ***********************************************************************/
void saveAndQuit(char board[][9])
{
   char fileNameOut[256];
   cout << "What file would you like to write your board to: ";
   cin  >> fileNameOut;
   
   ofstream fout(fileNameOut);
   if (fout.fail())
   {
      fout.close();
      cout << "Unable to write to file "
           << fileNameOut << endl;
   }
   else
   {
      for (int row = 0; row < 9; row++)
         for (int col = 0; col < 9; col++)
            // Writes the file and converts ' ' back to '0'
            fout << (board[row][col] == ' ' ? '0' : board[row][col])
                 << (col == 8 ? '\n' : ' ');
   
      fout.close();
      cout << "Board written successfully\n";
   }
}
