/***********************************************************************
* Program:
*    Project 13, Sudoku
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program allows the user to play a game of sudoku from a file,
*    allows the user to edit the board with the user's answers, and
*    finally saves their game to a new file when they quit the program.
*    This version also checks the validity of the user's answer
*    according to the rules and restricts the answer as such.
*
*    Estimated:  3.0 hrs   
*    Actual:     7.0 hrs
*      The most difficult part was figuring out how to check the answers.
*      I was having all sorts of problems and it took me a long time to
*      figure it out.
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile(char board[][9]);
void displayOptions();
void displayBoard(char board[][9]);
void computeValues(char board[][9]);
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
            cin.ignore();
            break;
         case 'D':
            displayBoard(board);
            cin.ignore();
            break;
         case 'E':
            editSquare(board);
            cin.ignore();
            break;
         case 'S':
            computeValues(board);
            cin.ignore();
            break;
         case 'Q':
            saveAndQuit(board);
            cin.ignore();
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
 * Checks to values of the surrounding cells and lists all values not
 * there as possible choices to fill the square in with.
 ***********************************************************************/
void computeValues(char board[][9])
{
   char letter;
   int number;
   int row;
   int col;
   
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

   // Error to keep from checking a filled square
   if (board[row][col] != ' ')
      cout << "ERROR: Square '"
           << letter << number
           << "' is filled\n";
   else
   {      
      string notPoss;
      bool isPoss[9];
      
      // Check the rest of the column
      for (int iRow = 0; iRow < 9; iRow++)
         if (board[iRow][col] != ' ')
            notPoss += board[iRow][col];

      // Check the rest of the row
      for (int iCol = 0; iCol < 9; iCol++)
         if (board[row][iCol] != ' ')
            notPoss += board[row][iCol];

      // Check the box it is in
      int boxNum;
      if (col < 3 && row < 3)
         boxNum = 1;
      if (col > 2 && col < 6 && row < 3)
         boxNum = 2;
      if (col > 5 && row < 3)
         boxNum = 3;
      if (col < 3 && row > 2 && row < 6)
         boxNum = 4;
      if (col > 2 && col < 6 && row > 2 && row < 6)
         boxNum = 5;
      if (col > 5 && row > 2 && row < 6)
         boxNum = 6;
      if (col < 3 && row > 5)
         boxNum = 7;
      if (col > 2 && col < 6 && row > 5)
         boxNum = 8;
      if (col > 5 && row > 5)
         boxNum = 9;

      // Check the numbers in the box   
      switch (boxNum)
      {
         case 1:
            for (int iRow = 0; iRow < 3; iRow++)
               for (int iCol = 0; iCol < 3; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 2:
            for (int iRow = 0; iRow < 3; iRow++)
               for (int iCol = 3; iCol < 6; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 3:
            for (int iRow = 0; iRow < 3; iRow++)
               for (int iCol = 6; iCol < 9; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 4:
            for (int iRow = 3; iRow < 6; iRow++)
               for (int iCol = 0; iCol < 3; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 5:
            for (int iRow = 3; iRow < 6; iRow++)
               for (int iCol = 3; iCol < 6; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 6:
            for (int iRow = 3; iRow < 6; iRow++)
               for (int iCol = 6; iCol < 9; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 7:
            for (int iRow = 6; iRow < 9; iRow++)
               for (int iCol = 0; iCol < 3; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 8:
            for (int iRow = 6; iRow < 9; iRow++)
               for (int iCol = 3; iCol < 6; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 9:
            for (int iRow = 6; iRow < 9; iRow++)
               for (int iCol = 6; iCol < 9; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
      }

      // Set all of isPoss to TRUE
      for (int i = 0; i < 9; i++)
         isPoss[i] = true;

      // Set isPoss to false depending on if the number is already
      //   there.
      for (int num = 1; num < 9; num++)
         for (int i = 0; i < notPoss.length(); i++)
            // Check characters against integers
            switch (notPoss[i])
            {
               case '1':
                  isPoss[0] = false;
                  break;
               case '2':
                  isPoss[1] = false;
                  break;
               case '3':
                  isPoss[2] = false;
                  break;
               case '4':
                  isPoss[3] = false;
                  break;
               case '5':
                  isPoss[4] = false;
                  break;
               case '6':
                  isPoss[5] = false;
                  break;
               case '7':
                  isPoss[6] = false;
                  break;
               case '8':
                  isPoss[7] = false;
                  break;
               case '9':
                  isPoss[8] = false;
                  break;
            }


      // Assign numbers to possible
      int possible[9];
      int possCount = 0;
      for (int i = 0; i < 9; i++)
         if (isPoss[i] == true)
         {
            possible[possCount] = i + 1;
            possCount++;
         }
      possible[possCount] = '\0';
      
         
      // Display results
      cout << "The possible values for '" << letter << number
           << "' are: ";      
      for (int i = 0; i < possCount; i++)
      {
         cout << possible[i];
         if (possible[i + 1] != '\0')
            cout << ", ";
      }
      
      cout << endl;
   }
   
}


/**********************************************************************
 * Takes an input from the user for a desired square and then prompts the
 * user for the new value and enters it into the board. This also checks
 * to see if the number is a valid entry according to the rules of Sudoku
 * and displays an error if it is not.
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

      // Check to see if it is a valid entry
      string notPoss;
      bool isPoss[9];
      
      // Check the rest of the column
      for (int iRow = 0; iRow < 9; iRow++)
         if (board[iRow][col] != ' ')
            notPoss += board[iRow][col];

      // Check the rest of the row
      for (int iCol = 0; iCol < 9; iCol++)
         if (board[row][iCol] != ' ')
            notPoss += board[row][iCol];

      // Check the box it is in
      int boxNum;
      if (col < 3 && row < 3)
         boxNum = 1;
      if (col > 2 && col < 6 && row < 3)
         boxNum = 2;
      if (col > 5 && row < 3)
         boxNum = 3;
      if (col < 3 && row > 2 && row < 6)
         boxNum = 4;
      if (col > 2 && col < 6 && row > 2 && row < 6)
         boxNum = 5;
      if (col > 5 && row > 2 && row < 6)
         boxNum = 6;
      if (col < 3 && row > 5)
         boxNum = 7;
      if (col > 2 && col < 6 && row > 5)
         boxNum = 8;
      if (col > 5 && row > 5)
         boxNum = 9;

      // Check the numbers in the box   
      switch (boxNum)
      {
         case 1:
            for (int iRow = 0; iRow < 3; iRow++)
               for (int iCol = 0; iCol < 3; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 2:
            for (int iRow = 0; iRow < 3; iRow++)
               for (int iCol = 3; iCol < 6; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 3:
            for (int iRow = 0; iRow < 3; iRow++)
               for (int iCol = 6; iCol < 9; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 4:
            for (int iRow = 3; iRow < 6; iRow++)
               for (int iCol = 0; iCol < 3; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 5:
            for (int iRow = 3; iRow < 6; iRow++)
               for (int iCol = 3; iCol < 6; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 6:
            for (int iRow = 3; iRow < 6; iRow++)
               for (int iCol = 6; iCol < 9; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 7:
            for (int iRow = 6; iRow < 9; iRow++)
               for (int iCol = 0; iCol < 3; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 8:
            for (int iRow = 6; iRow < 9; iRow++)
               for (int iCol = 3; iCol < 6; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
         case 9:
            for (int iRow = 6; iRow < 9; iRow++)
               for (int iCol = 6; iCol < 9; iCol++)
                  if (board[iRow][iCol] != ' ')
                     notPoss += board[iRow][iCol];
            break;
      }

      // Set all of isPoss to TRUE
      for (int i = 0; i < 9; i++)
         isPoss[i] = true;

      // Set isPoss to false depending on if the number is already
      //   there.
      for (int num = 1; num < 9; num++)
         for (int i = 0; i < notPoss.length(); i++)
            // Check characters against integers
            switch (notPoss[i])
            {
               case '1':
                  isPoss[0] = false;
                  break;
               case '2':
                  isPoss[1] = false;
                  break;
               case '3':
                  isPoss[2] = false;
                  break;
               case '4':
                  isPoss[3] = false;
                  break;
               case '5':
                  isPoss[4] = false;
                  break;
               case '6':
                  isPoss[5] = false;
                  break;
               case '7':
                  isPoss[6] = false;
                  break;
               case '8':
                  isPoss[7] = false;
                  break;
               case '9':
                  isPoss[8] = false;
                  break;
            }


      // Assign numbers to possible
      int possible[9];
      int possCount = 0;
      for (int i = 0; i < 9; i++)
         if (isPoss[i] == true)
         {
            possible[possCount] = i + 1;
            possCount++;
         }
      possible[possCount] = '\0';


      //Check validity
      bool valid = false;
      for (int x = 0; possible[x]; x++)
         switch (newVal)
         {
            case '1':
               if (possible[x] == 1)
                  valid = true;
               break;
            case '2':
               if (possible[x] == 2)
                  valid = true;
               break;
            case '3':
               if (possible[x] == 3)
                  valid = true;
               break;
            case '4':
               if (possible[x] == 4)
                  valid = true;
               break;
            case '5':
               if (possible[x] == 5)
                  valid = true;
               break;
            case '6':
               if (possible[x] == 6)
                  valid = true;
               break;
            case '7':
               if (possible[x] == 7)
                  valid = true;
               break;
            case '8':
               if (possible[x] == 8)
                  valid = true;
               break;
            case '9':
               if (possible[x] == 9)
                  valid = true;
               break;
         }

      // Assign new value or display error if invalid.
      if (valid)
         board[row][col] = newVal;
      else
         cout << "ERROR: Value '"
              << newVal
              << "' in square '"
              << letter << number
              << "' is invalid\n";
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
