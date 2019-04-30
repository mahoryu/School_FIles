// File: address.h

#ifndef ADDRESS_H
#define ADDRESS_H

// Put your Address class here

class Address
{
  private:
   string street;
   string city;
   string state;
   string zip;
  public:
   //constructors
   Address();
   Address(string street, string city, string state, string zip);

   //getters
   string getStreet() {string val = street; return val;}
   string getCity()   {string val = city; return val;}
   string getState()  {string val = state; return val;}
   string getZip()    {string val = zip; return val;}
   
   //setters
   void setStreet(string street) {this->street = street;}
   void setCity(string city)     {this->city = city;}
   void setState(string state)   {this->state = state;}
   void setZip(string zip)       {this->zip = zip;}

   //display
   void display();
};

#endif
