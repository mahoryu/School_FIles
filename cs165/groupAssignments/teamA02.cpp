/***********************************************************************
* Program:
*    Team Assignment 02, Scriptues
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

struct Scripture
{
   string bookName;
   int chapter;
   int verse;
};

struct Insight
{
   Scripture reference;
   string insight;
};

Scripture promptScripture();
void displayScripture(const Insight &thoughts);
void promptInsight(Insight &thoughts);
void displayInsight(const Insight &thoughts);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't
 * forget to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   
   Insight thoughts;

   promptInsight(thoughts);
   displayInsight(thoughts);
   
   return 0;
}

Scripture promptScripture()
{
   Scripture script;
   
   cout << "Please enter a Scripture:\n\tBook Name: ";
   getline(cin, script.bookName);
   cout << "\tChapter: ";
   cin  >> script.chapter;
   cin.ignore();
   cout << "\tVerse: ";
   cin  >> script.verse;
   cin.ignore();

   return script;
}

void displayScripture(const Insight &thoughts)
{
   cout << thoughts.reference.bookName << " "
        << thoughts.reference.chapter << ":"
        << thoughts.reference.verse << endl;
}


void promptInsight(Insight &thoughts)
{
   thoughts.reference = promptScripture();
   
   cout << "Please enter your thoughts on this scripture:\n";
   getline(cin, thoughts.insight);
}

void displayInsight(const Insight &thoughts)
{
   displayScripture(thoughts);
   cout << thoughts.insight
        <<endl;
}
