/***********************************************************************
 * Header:
 *    WHOLENUMBER
 * Summary:
 *    This will contain the prototype for wholeNumber class.
 * Author
 *    Adrian Lane, Ethan Holden, Kenyon Bunker
 ************************************************************************/

#ifndef WHOLENUMBER_H
#define WHOLENUMBER_H
//#include "C:\Users\Kenyon B\source\repos\ajlane17\cs235\week07\list.h" //for Kenyon remove before submition
#include "list.h"
using std::ostream;
using std::ios;
using namespace custom;
// wholeNumber class
class wholeNumber
{
private:
   list <unsigned int> num;
public:
/**************************************************
 * Constructors and Destructors
 *************************************************/
   wholeNumber();
   wholeNumber(unsigned int num);
   wholeNumber(const wholeNumber & rhs);
   ~wholeNumber();

/**************************************************
 * Operators
 *************************************************/
   friend ostream & operator <<(ostream & out, const wholeNumber & rhs);
   wholeNumber & operator = (const wholeNumber & rhs);
   wholeNumber& operator += (const wholeNumber & rhs);   
};

#endif // WHOLENUMBER_H


