/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your Book class here
class Book
{
private:
   string title;
   string author;
   int publicationYear;
public:
   void promptBookInfo();
   void displayBookInfo();
};
   
// TODO: Define your TextBook class here
class TextBook : public Book
{
private:
   string subject;
public:
   void promptSubject();
   void displaySubject();
};

// TODO: Add your PictureBook class here
class PictureBook : public Book
{
private:
   string illustrator;
public:
   void promptIllustrator();
   void displayIllustrator();
};


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
   Book book;
   book.promptBookInfo();
   cout << endl;
   book.displayBookInfo();
   cout << endl;
   
   // Declare a TextBook object here and call its methods
   TextBook tBook;
   tBook.promptBookInfo();
   tBook.promptSubject();
   cout << endl;
   tBook.displayBookInfo();
   tBook.displaySubject();
   cout << endl;

   // Declare a PictureBook object here and call its methods
   PictureBook pBook;
   pBook.promptBookInfo();
   pBook.promptIllustrator();
   cout << endl;
   pBook.displayBookInfo();
   pBook.displayIllustrator();
      
   return 0;
}

// Book methods 
void Book :: promptBookInfo()
{
   cout << "Title: ";
   getline(cin, title);
   cin.clear();
      
   cout << "Author: ";
   getline(cin, author);
   cin.clear();
      
   cout << "Publication Year: ";
   cin  >> publicationYear;

   cin.ignore(256, '\n');
}

void Book :: displayBookInfo()
{
   cout << title << " ("
        << publicationYear
        << ") by " << author
        << endl;
}

// TextBook methods
void TextBook :: promptSubject()
{
   cout << "Subject: ";
   getline(cin, subject);
   cin.clear();
}

void TextBook :: displaySubject()
{
   cout << "Subject: "
        << subject << endl;
}

// PictureBook methods
void PictureBook :: promptIllustrator()
{
   cout << "Illustrator: ";
   getline(cin, illustrator);
   cin.clear();
}

void PictureBook :: displayIllustrator()
{
   cout << "Illustrated by "
        << illustrator << endl;
}
