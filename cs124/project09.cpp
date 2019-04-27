/***********************************************************************
* Program:
*    Project 09, Mad Lib Question Extractor
*    Brother Honeycutt, CS124
* Author:
*    Ethan Holden
* Summary: 
*    This program prompts the user for the name of a Mad Lib file and
*    then extracts and displays all the questions in the file while
*    prompting the user for answers to each question one at a time.
*
*    Estimated:  5.5 hrs   
*    Actual:     3.0 hrs
*      The most difficult part was either getting the getQuestions
*      function to extract the questions from the file, or it was getting
*      getAnswers to display the questions and ask for the user input and
*      then getting it to store the answers in an array properly.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void promptFile(char madLibString[]);
void getQuestions(char * pMadLibString, char * pQuestions);
void getAnswers(char * pQuestions, char * pAnswers);

/**********************************************************************
 * Function main sets up the arrays the program uses and then calls on
 * the functions one at a time to first prompt for a file, extract the
 * questions from the file and then receive the answers from the user.
 ***********************************************************************/
int main()
{
   const int SIZE = 1024;

   // Setting up arrays and their pointers
   char madLibString[SIZE];
   char * pMadLibString;
   pMadLibString = &madLibString[0];
   
   char questions[SIZE];
   char * pQuestions;
   pQuestions = &questions[0];

   char answers[SIZE];
   char * pAnswers;
   pAnswers = &answers[0];

   // Call on all functions
   promptFile(madLibString);
   getQuestions(madLibString, questions);
   getAnswers(questions, answers);

   cout << endl;
   return 0;
}

/**********************************************************************
 * Function promptFile asks the user for a file name and then writes the
 * file to the madLibString array.
 ***********************************************************************/
void promptFile(char madLibString[])
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
      return;
   }

   // Write file to madLibString array.
   for (int i = 0; fin != '\0'; i++)
      fin >> madLibString[i];
   
   fin.close();
   // Empties out the cin from the file name input so that it doesn't
   //    mess with data entered later.
   cin.ignore();
   return;
}

/**********************************************************************
 * Function getQuestions reads the madLibString array and extracts all of
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

   return;
}

/**********************************************************************
 * Function getAnswers takes a look at the questions array and displays
 * them in a user friendly format to prompt the user for the answers and
 * then stores the answers int an array for later use.
 ***********************************************************************/
void getAnswers(char * pQuestions, char * pAnswers)
{
   char * pQ;
   char * pA;
   pA = pAnswers;
   
   cout << "\t";

   // Search for the '%' marker and '_' characters to convert the file
   //    and put spaces in the questions.
   for (pQ = pQuestions; *pQ; pQ++)
      if (*pQ == '%')
      {
         char tempText[256] = "a";
         cout << ": ";

         // Store input in tempText to transfer it to the answers array.
         cin.getline(tempText, 256);
         {
            for (int i = 0; tempText[i]; i++)
            {
               *pA = tempText[i];
               pA++;
            }
            *pA = '%';
            pA++;
         }
         // Search for end of array in order to stop the "\t" from 
         //    happening an extra time.
         if (*(pQ + 2) == '\0')
            cout << "Thank you for playing.";
         else
            cout << "\t";
      }
      // Replace '_' with " "
      else if (*pQ == '_')
         cout << " ";
      else
         cout << *pQ;
   // end the answer string
   *pA = '\0';
   
   return;
}
