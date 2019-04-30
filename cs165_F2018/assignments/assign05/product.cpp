/***************************************************************
 * File: product.cpp
 * Author: Ethan Holden
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "product.h"

//Constructors

/***************************************************************
 * sets defualt values.
 ***************************************************************/
Product :: Product()
{
   name = "none";
   description = "";
   weight = 0;
   basePrice = 0;
}

/***************************************************************
 * sets values for those specified.
 ***************************************************************/
Product :: Product(string name, string description,
                   float basePrice, float weight)
{
   this->name = name;
   this->description = description;
   this->basePrice = basePrice;
   this->weight = weight;
}

//Methods

/***************************************************************
 * Returns the sales tax for the item. 
 ***************************************************************/
inline float Product :: getSalesTax()
{
   return (basePrice * .06);
}

/***************************************************************
 * Calculates the shipping based on the item's weight.
 ***************************************************************/
float Product :: getShippingCost()
{
   if (weight > 5)
      return (2 + (.1 * (weight - 5)));
   else
      return 2;
}

/***************************************************************
 * Returns the total cost of the product item.
 ***************************************************************/
inline float Product :: getTotalPrice()
{
   return getShippingCost() + basePrice + getSalesTax();
}

/***************************************************************
 * Displays the name, price, and description of the item.
 ***************************************************************/
void Product :: displayAdvertising()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << name << " - $" << basePrice << endl;
   cout << "(" << description << ")\n";
}

/***************************************************************
 * displays product price, name, and weight
 ***************************************************************/
void Product :: displayInventory()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "$" << basePrice << " - "
        << name << " - ";
   
   cout.precision(1);
   cout << weight << " lbs\n";
}

/***************************************************************
 * 
 * 
 ***************************************************************/
void Product :: displayReceipt()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << name << endl;
   cout << setw(2) << " " << "Price:" << setw(10) << "$"
        << setw(8) << basePrice << endl;
   cout << setw(2) << " " << "Sales tax:" << setw(6) << "$"
        << setw(8) << getSalesTax() << endl;
   cout << setw(2) << " " << "Shipping cost:" << setw(2) << "$"
        << setw(8) << getShippingCost() << endl;
   cout << setw(2) << " " << "Total:" << setw(10) << "$"
        << setw(8) << getTotalPrice() << endl;
   
}
