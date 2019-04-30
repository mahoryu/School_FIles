/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <iomanip>
using namespace std;

class Money
{
  private:
   int dollars;
   int cents;
      
  public:
  Money()
   {
      dollars = 0;
      cents = 0;
   }
  Money(const int &dollars)
   {
      setDollars(dollars);
      cents = 0;
   }
   
  Money(const int &dollars, const int &cents)
  {
      setDollars(dollars);
      setCents(cents);
  }
  
  void prompt();
  void display() const;
  void setDollars(int dollars);
  void setCents(int cents);
  int getDollars() const {return dollars;}
  int getCents() const {return cents;}
};

#endif
