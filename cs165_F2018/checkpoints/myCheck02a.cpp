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
   int id;
};

void displayStudent(Student student);
Student promptStudent();

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Student student;
   student = promptStudent();
   cout << endl
        << "Your information:\n";
   displayStudent(student);
   
   return 0;
}

void displayStudent(Student student)
{
   cout << student.id << " - " << student.firstName
        << " " << student.lastName << endl;
}

Student promptStudent()
{
   Student student;
   cout << "Please enter your first name: ";
   cin  >> student.firstName;
   cout << "Please enter your last name: ";
   cin  >> student.lastName;
   cout << "Please enter your id number: ";
   cin  >> student.id;

   return student;
}
