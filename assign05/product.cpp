/***************************************************************
 * File: product.cpp
 * Author: Ethan Holden
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// put your method bodies here
 
Product :: Product()
{
   name = "none";
   description = "";
   bPrice = 0;
   weight = 0;
}

Product :: Product(const string &name, const string &description, 
                   const float &bPrice, const float &weight)
{
   this->name = name;
   this->description = description;
   this->bPrice = bPrice;
   this->weight = weight;
}

float Product :: getSalesTax() const
{
   float salesTax = getBasePrice() * .06;
   return salesTax;
}

float Product :: getShippingCost() const
{
   float shippingCost = 2.00;
   if (getWeight() > 5.0)
      shippingCost += .10 * ((int)getWeight() - 5);
	
   return shippingCost;
}

float Product :: getTotalPrice() const
{
   float totalPrice = getBasePrice();
   totalPrice += getSalesTax();
   totalPrice += getShippingCost();
	
   return totalPrice;
}

void Product :: displayAdvertising() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << getName() << " - $" << getBasePrice() << endl
        << "(" << getDescription() << ")\n";
}

void Product :: displayInventory() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "$" << getBasePrice() << " - " << getName()
        << " - ";
   cout.precision(1);
   cout << getWeight() << " lbs\n";
}

void Product :: displayReceipt() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
	
   float salesTax = getSalesTax();
   float shipping = getShippingCost();
   float total = getTotalPrice();
	
   cout << name << endl
        << "  " << setw(15) << left  << "Price:" 
        << "$"  << setw(8)  << right << bPrice << endl;
   cout << "  " << setw(15) << left  << "Sales tax:" 
        << "$"  << setw(8)  << right << salesTax << endl;
   cout << "  " << setw(15) << left  << "Shipping cost:" 
        << "$"  << setw(8)  << right << shipping << endl;
   cout << "  " << setw(15) << left  << "Total:" 
        << "$"  << setw(8)  << right << total << endl;
}
