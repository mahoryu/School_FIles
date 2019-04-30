/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

struct Complex
{
   double real;
   double imaginary;
};

Complex prompt(Complex &c1);
Complex addComplex(const Complex &c1, const Complex &c2);
void display(const Complex &cSum);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Complex c1;
   Complex c2;

   c1 = prompt(c1);
   c2 = prompt(c2);
   Complex cSum = addComplex(c1, c2);

   display (cSum);
   
   return 0;
}

Complex prompt(Complex &c1)
{
   cout << "Real: ";
   cin  >> c1.real;
   cout << "Imaginary: ";
   cin  >> c1.imaginary;

   return c1;
}

Complex addComplex(const Complex &c1, const Complex &c2)
{
   Complex cSum =
   {
      c1.real + c2.real,
      c1.imaginary + c2.imaginary
   };

   return cSum;
}

void display(const Complex &cSum)
{
   cout << "\nThe sum is: "
        << cSum.real << " + "
        << cSum.imaginary << "i\n";
}
