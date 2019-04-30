// File: customer.cpp

#include <iostream>
#include <string>
using namespace std;

#include "customer.h"

//Constructors

/***************************************************************
 * sets default values.
 **************************************************************/
Customer :: Customer()
{
   name = "unspecified";
}

/***************************************************************
 * sets values to those specified.
 **************************************************************/
Customer :: Customer(string name, Address address)
{
   this->name = name;
   this->address = address;
}

//Methods

/***************************************************************
 * displays the customer's name and address
 **************************************************************/
void Customer :: display()
{
   cout << name << endl;
   address.display();
}
