// File: address.cpp

#include "address.h"

// Put your method bodies for the address class here
#include <iostream>
#include <string>
using namespace std;

Address :: Address()
{
   street = "unknown"; 
   city = ""; 
   state = ""; 
   zip = "00000";
}

void Address :: display() const
{
   cout << getStreet() << endl
        << getCity() << ", " << getState() 
        << " " << getZip() << endl;
}

Address :: Address(const string &street, const string &city, 
                   const string &state, string const &zip)
{
   setStreet(street);
   setCity(city);
   setState(state);
   setZip(zip);
}
