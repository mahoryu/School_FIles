// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "address.h"

// put your Customer class here
class Customer
{
  private:
   string name;
   Address address;
  public:
   //constructors
   Customer();
   Customer(string name, Address address);
   
   //getters
   string getName()     {string val = name; return val;}
   Address getAddress() {Address val = address; return val;}
   
   //setters
   void setName(string name)        {this->name = name;}
   void setAddress(Address address) {this->address = address;}
   
   //display
   void display();
};

#endif
