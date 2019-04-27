// File: address.h

#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
using namespace std;

// Put your Address class here
class Address
{
  private:
   string street;
   string city;
   string state;
   string zip;
  public:
   Address();
   Address(const string &street, const string &city, 
           const string &state, string const &zip);
   string getStreet() const {return street;}
   string getCity() const {return city;}
   string getState() const {return state;}
   string getZip() const {return zip;}
   void setStreet(string street) {this->street = street;}
   void setCity(string city) {this->city = city;}
   void setState(string state) {this->state = state;}
   void setZip(string zip) {this->zip = zip;}
   void display() const;
};

#endif
