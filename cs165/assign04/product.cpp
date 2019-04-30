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

/***************************************************************
 * Prompts the user for the product name, the description, the
 * weight, and the price.
 ***************************************************************/
void Product :: prompt()
{
   cout << "Enter name: ";
   getline(cin, name);
   cout << "Enter description: ";
   getline(cin, description);
   cout << "Enter weight: ";
   cin  >> weight;
      
   do
   {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter price: ";
      cin  >> bPrice;
   }
   while(bPrice < 0 || cin.fail());
}

/***************************************************************
 * Calculates the product sales tax.
 ***************************************************************/
float Product :: getSalesTax()
{
   float salesTax = bPrice * .06;
   return salesTax;
}

/***************************************************************
 * Calculates the shipping cost.
 ***************************************************************/
float Product :: getShippingCost()
{
   float shippingCost = 2.00;
   if (weight > 5.0)
      shippingCost += .10 * ((int)weight - 5);
	
   return shippingCost;
}

/***************************************************************
 * Calculates the total price.
 ***************************************************************/
float Product :: getTotalPrice()
{
   float totalPrice = bPrice;
   totalPrice += getSalesTax();
   totalPrice += getShippingCost();
	
   return totalPrice;
}

/***************************************************************
 * Displays the advertisment.
 ***************************************************************/
void Product :: displayAd()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << name << " - $" << bPrice << endl
        << "(" << description << ")\n";
}

/***************************************************************
 * Displays the Inventory entry.
 ***************************************************************/
void Product :: displayInv()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "$" << bPrice << " - " << name
        << " - ";
   cout.precision(1);
   cout << weight << " lbs\n";
}

/***************************************************************
 * Displays the Receipt.
 ***************************************************************/
void Product :: displayReceipt()
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
   cout<< "  "  << setw(15) << left  << "Total:" 
       << "$"  << setw(8)  << right << total << endl;
}
