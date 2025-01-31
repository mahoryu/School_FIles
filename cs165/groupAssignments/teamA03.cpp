/**********************************************************************
 * File: ta03.cpp
 * Author: Devin, Ethan, Lucas
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/***********************************************************************
 * Struct: Scripture
 * Description: Holds the reference to a scripture (book, chapter, verse
 ***********************************************************************/
struct Scripture
{
   string book;
   int chapter;
   int startVerse;
   int endVerse;
};

/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/
void display(const Scripture &scripture)
{
   cout << scripture.book << " ";
   cout << scripture.chapter << ":";
   cout << scripture.startVerse;

   if (scripture.endVerse > 0)
   {
      cout << "-" << scripture.endVerse;
   }

}


/***********************************************************************
 * Function: parseLine
 * Description: 
 ***********************************************************************/
void parseLine(string line, Scripture & newScripture)
{
   stringstream buffer(line);

   buffer >> newScripture.book;
   buffer >> newScripture.chapter;
   buffer >> newScripture.startVerse;
   buffer >> newScripture.endVerse;

   if (buffer.fail())
   {
      newScripture.endVerse = 0;
   }

}

/***********************************************************************
 * Function: parseFile
 * Description: Gets file from user.
 ***********************************************************************/
bool parseFile(string file)
{
   ifstream fin(file.c_str());

   if (fin.fail())
   {
      cout << "Error opening file: " << file;
      return false;
   }

   string line;
   
   while (getline(fin, line))
   {
      Scripture newScripture;
      parseLine(line, newScripture);

      display (newScripture);
      cout << endl;

   }

   fin.close();

   return true;
}

/***********************************************************************
 * Function: promptFile
 * Description: Gets file from user.
 ***********************************************************************/
string promptFile()
{
   string file;

   cout << "Please enter the name of the file: ";
   cin  >> file;

   return file;
}
   
/***********************************************************************
 * Function: main
 * Description: The driver for the program.
 ***********************************************************************/
int main()
{
   string file = promptFile();
   parseFile(file);

   return 0;
}
