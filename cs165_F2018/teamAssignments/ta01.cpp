#include <iostream>
#include <string>
using namespace std;

struct Scripture
{
   string book;
   int chapter;
   int verse;
};

struct Insight
{
   Scripture scripture;
   string message;
};

void displayScripture(Scripture scrip)
{
   cout << scrip.book << " "
        << scrip.chapter << ":"
        << scrip.verse << endl;
}

Scripture promptScripture()
{
   Scripture scrip;
   cout << "Please enter a scripture: \n"
        << "Book: ";
   getline(cin, scrip.book);
   cout << "Chapeter: ";
   cin  >> scrip.chapter;
   cout << "Verse: ";
   cin  >> scrip.verse;

   cin.ignore();
   
   return scrip;
}

Insight promptInsight()
{
   Insight i;
   i.scripture = promptScripture();

   cout << "Please enter your insight about this scripture: \n";
   getline(cin, i.message);

   return i;
}

void displayInsight(Insight i)
{
   displayScripture(i.scripture);
   cout << i.message << endl;
}

int main()
{
   /*
   Scripture s1[3];

   for (int i = 0; i < 3; i++)
      s1[i] = promptScripture();
   for (int i = 0; i < 3; i++)
      displayScripture(s1[i]);
   */

   Insight i = promptInsight();
     
   displayInsight(i);
   
   return 0;
}
