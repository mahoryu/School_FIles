/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
   int dollars;
   int cents;
      
public:
   void prompt();
   void display() const;
   void setDollars(int dollars);
   void setCents(int cents);
   int getDollars() const {return dollars;}
   int getCents() const {return cents;}
};

#endif
