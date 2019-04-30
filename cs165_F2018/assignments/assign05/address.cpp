//File: address.cpp
#include <iostream>
#include <string>
using namespace std;

#include "address.h"

//Constructors

/*************************************************************
 * sets default values
 *************************************************************/
Address :: Address()
{
   street = "unknown";
   zip = "00000";
   state = "";
   city = "";
}

/*************************************************************
 * sets values to those specified.
 *************************************************************/
Address :: Address(string street, string city, string state, string zip)
{
   this->street = street;
   this->city = city;
   this->state = state;
   this->zip = zip;
}

//methods

/*************************************************************
 * Displays the address to the screen in the proper format.
 *************************************************************/
void Address :: display()
{
   cout << street << endl;
   cout << city << ", " << state
        << " " << zip << endl;
}
