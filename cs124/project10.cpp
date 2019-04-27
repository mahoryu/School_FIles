/***********************************************************************
* Program:
*    Project 10, Mad Lib Game 
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program prompts the user for the name of a Mad Lib file and
*    then extracts and displays all the questions in the file while
*    prompting the user for answers to each question one at a time.
*    It then Takes the Mad Lib and displays it for the user with their
*    answers placed into the Mad Lib. The program then asks the user if
*    they want to play again and then resets everything if they do.
*
*    Estimated:  5.0 hrs   
*    Actual:     8.0 hrs
*      The most difficult part was figuring out to store the data so that
*      all the words were separated into their own array within the
*      string so that the program could put the proper spaces in-between.
*      The other hard part was figuring out how to clear all the arrays
*      so that it could be played again without having any left over data
*      to mess it up.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

const int WORDS = 256;
const int SIZE = 32;

bool promptFile(char madLibArray[][SIZE], int &fileWordSize, char
                madLibString[]);
void getQuestions(char * pMadLibString, char * pQuestions);
void getAnswers(char * pQuestions, char answers[][SIZE], int
                &answerWords);
void display(int fileWordSize, char madLibArray[][SIZE], char
             answers[][SIZE]);
char promptPlayAgain();
void clearStrings(char madLibArray[][SIZE], char madLibString[], char
                  questions[], char answers[][SIZE], int answerWords,
                  int fileWordSize);

/**********************************************************************
 * Function main sets up the arrays the program uses and then calls on
 * the functions one at a time to first prompt for a file, extract the
 * questions from the file and then receive the answers from the user.
 ***********************************************************************/
int main()
{
   char againQuest;
   
   // Setting up arrays and their pointers
   char madLibArray[WORDS][SIZE];

   char madLibString[1024];
   char * pMadLibString;
   pMadLibString = &madLibString[0];

   char questions[256];
   char * pQuestions;
   pQuestions = &questions[0];

   char answers[WORDS][SIZE];

   do
   {
      int answerWords = 0;
   
      int fileWordSize = 0;
      int * pFileWordSize;
      pFileWordSize = &fileWordSize;


   

      // Call on all functions
      if (!promptFile(madLibArray, fileWordSize, madLibString))
         return 0;
      getQuestions(pMadLibString, pQuestions);
      getAnswers(pQuestions, answers, answerWords);
      display(fileWordSize, madLibArray, answers);

      // Ask if they want to play again
      againQuest = promptPlayAgain();

      // Empty out the strings so that they are ready for the next file
      clearStrings(madLibArray, madLibString, questions, answers,
                   answerWords, fileWordSize);
   }
   while (againQuest == 'y');
   
   cout << "Thank you for playing.\n";
      
   return 0;
}

/**********************************************************************
 * Function promptFile asks the user for a file name and then writes the
 * file to the madLibArray array.
 ***********************************************************************/
bool promptFile(char madLibArray[][SIZE], int &fileWordSize, char
                madLibString[])
{
   // Prompt for file
   char fileName[256];
   cout << "Please enter the filename of the Mad Lib: ";
   cin  >> fileName;

   // Read file
   ifstream fin(fileName);
   // Return error if file name doesn't work for any reason
   if (fin.fail())
   {
      cout << "Unable to open file " << fileName << endl;
      return false;
   }

   // Write file to madLibArray array.
   for (int i = 0; fin != '\0'; i++)
   {
      fin >> madLibArray[i];
      fileWordSize++;
   }

   fin.close();
   fin.open(fileName);

   // Write to madLibString so that it can be traversed by a pointer.
   for (int i = 0; fin != '\0'; i++)
      fin >> madLibString[i];
   
   fin.close();
   // Empties out the cin from the file name input so that it doesn't
   //    mess with data entered later.
   cin.ignore();
   return true;
}

/**********************************************************************
 * Function getQuestions reads the madLibArray array and extracts all of
 * the questions from the text.
 ***********************************************************************/
void getQuestions(char * pMadLibString, char * pQuestions)
{
   char * pQ;
   pQ = pQuestions;
   // find the "<"
   for (char * pM = pMadLibString; *pM; pM++)
   {
      if (*pM == '<')
      {
         // Search for only questions and not special characters
         if (isalpha(*(pM + 1)))
         {
            // Capitalize the first letter and store it into the
            //    question array.
            *pQ = toupper(*(pM + 1));
            pQ++;
            for (pM += 2; *pM != '>'; pM++)
            {
               // Store the rest of the question
               *pQ = *pM;
               pQ++;
            }
            // Place a marker in the array to separate the questions
            //    one from another.
            *pQ = '%';
            pQ++;
         }
      }
      // End the questions array.
      *pQ = '\0';
   }
}

/**********************************************************************
 * Function getAnswers takes a look at the questions array and displays
 * them in a user friendly format to prompt the user for the answers and
 * then stores the answers int an array for later use.
 ***********************************************************************/
void getAnswers(char * pQuestions, char answers[][SIZE], int &answerWords)
{
   char * pQ;
   answerWords = 0;
   
   if (*pQuestions == '\0')
      cout << endl;
   else
   {
      cout << "\t";
      // Search for the '%' marker and '_' characters to convert the file
      //    and put spaces in the questions.
      for (pQ = pQuestions; *pQ; pQ++)
         if (*pQ == '%')
         {
            char tempText[256] = "a";
            cout << ": ";

            // Store input in tempText to transfer it to the answers
            //    array.
            cin.getline(tempText, 256);
            {
               for (int i = 0; tempText[i]; i++)
               {
                  answers[answerWords][i] = tempText[i];
               }
               answerWords++;
            }
            // Search for end of array in order to stop the "\t" from 
            //    happening an extra time.
            if (*(pQ + 2) == '\0')
               cout << endl;
            else
               cout << "\t";
         }
      // Replace '_' with " "
         else if (*pQ == '_')
            cout << " ";
         else
            cout << *pQ;
      // end the answer string
      answers[answerWords + 1][0] = '\0';
   }
   return;
}

/**********************************************************************
 * Takes the Mad Lib array and displays it for the user to see and then
 * either inserts the proper spacing and punctuation or fills in the
 * user's answer to replace the prompt with.
 ***********************************************************************/
void display(int fileWordSize, char madLibArray[][SIZE], char
             answers[][SIZE])
{
   int answerNum = 0;

   // Display first word of Mad Lib
   cout << madLibArray[0];
   for (int i = 1; i < fileWordSize; i++)
   {
      // No space before a word if a quote or new line was started
      if (madLibArray[i - 1][1] == '{' |
          madLibArray[i - 1][1] == '[' |
          madLibArray[i - 1][1] == '#')
      {
         // Making sure to still insert the answers.
         if (madLibArray[i][0] == '<')
         {
            switch (madLibArray[i][1])
            {
               case '#':
                  cout << endl;
                  break;
               case '{':
                  cout << "\"";
                  break;
               case '}':
                  cout << "\"";
                  break;
               case '[':
                  cout << "'";
                  break;
               case ']':
                  cout << "'";
                  break;
               default:
                  cout << answers[answerNum];
                  answerNum++;
                  break;
            }
         }
         // No Space between the a start quote and the next word.
         else
            cout << madLibArray[i];
      }

      // Add a space before each word after the first.
      else if (isalpha(madLibArray[i][0]))
         cout << " " << madLibArray[i];
      else
      {
         // Punctuation and prompts
         switch (madLibArray[i][0])
         {
            // Punctuation
            case '.':
               cout << ".";
               break;
            case ',':
               cout << ",";
               break;
            case '!':
               cout << "!";
               break;
            case '?':
               cout << "?";
               break;

               // Prompts
            case '<':
               switch (madLibArray[i][1])
               {
                  case '#':
                     cout << endl;
                     break;
                  case '{':
                     cout << " \"";
                     break;
                  case '}':
                     cout << "\"";
                     break;
                  case '[':
                     cout << " '";
                     break;
                  case ']':
                     cout << "'";
                     break;

                     // All non-special-character prompts
                  default:
                     cout << " " << answers[answerNum];
                     answerNum++;
                     break;
               }
         }
      }
   }
         
   cout << endl;
}


/**********************************************************************
 * Prompts the user to see if they want to play again.
 ***********************************************************************/
char promptPlayAgain()
{
   char againQuest;
   cout << "Do you want to play again (y/n)? ";
   cin  >> againQuest;

   return againQuest;
}

/**********************************************************************
 * This function clears out all of the strings so the game can be played
 * again.
 ***********************************************************************/
void clearStrings(char madLibArray[][SIZE], char
                  madLibString[], char questions[], char
                  answers[][SIZE], int answerWords,
                  int fileWordSize)
{
   for (int i = 0; i < fileWordSize; i++)
      for (int y = 0; madLibArray[i][y]; y++)
         madLibArray[i][y] = '\0';

   for (int i = 0; madLibString[i]; i++)
      madLibString[i] = '\0';

   for (int i = 0; questions[i]; i++)
      questions[i] = '\0';

   for (int i = 0; i < answerWords; i++)
      for (int y = 0; answers[i][y]; y++)
         answers[i][y] = '\0';
}
