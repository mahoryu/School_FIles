/***********************************************************************
* Program:
*    Checkpoint 02a, Structs
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

struct Student
{
   string firstName;
   string lastName;
   int idNumber;
};

void prompt(Student &user);
void display(const Student &user);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Student user;
   prompt(user);
   display(user);
            
   return 0;
}

void prompt(Student & user)
{
   cout << "Please enter your first name: ";
   cin  >> user.firstName;
   cout << "Please enter your last name: ";
   cin  >> user.lastName;
   cout << "Please enter your id number: ";
   cin  >> user.idNumber;
}

void display(const Student & user)
{
   cout << "\nYour information:\n"
        << user.idNumber << " - "
        << user.firstName << " "
        << user.lastName << endl;
}
