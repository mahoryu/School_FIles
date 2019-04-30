/**********************************************************************
 * File: ta03.cpp
 * Author: Br. Burton
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <list>
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
   int verse;
};
/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/
void display(const Scripture &scripture)
{
   cout << scripture.book << " ";
   cout << scripture.chapter << ":";
   cout << scripture.verse;
}
string prompt()
{
   cout << "Enter file name: \n";
   string fileName;
   cin >> fileName;
   return fileName;
}
Scripture parseLine(string line)
{
   Scripture script;
   stringstream sin(line);
   sin >> script.book;
   sin >> script.chapter;
   sin >> script.verse;
   return script;
}
bool readFile(string fileName, list<Scripture> &scriptList)
{
   fstream fin(fileName.c_str());
   if (fin.fail())
   {
      cout << "Dont be stupid\n";
      return false;
   }
   string line;
   while (getline(fin, line))
   {
      Scripture script = parseLine(line);
      scriptList.push_front(script);
   }
   return true;
}
/***********************************************************************
 * Function: main
 * Description: The driver for the program.
 ***********************************************************************/
int main()
{
   string fileName = prompt();
   list<Scripture> myList;
   if (!readFile(fileName, myList)){
      return 1;
   }
   // Insert your code here to prompt for the name of a file
   // and pass it to a readFile function
   cout << "Scriptures in file:\n";
   while (myList.size())
   {
      display(myList.front());
      cout << endl;
      myList.pop_front();
   }
   return 0;
}
