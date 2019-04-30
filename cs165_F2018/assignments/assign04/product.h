/***************************************************************
 * File: product.h
 * Author: Ethan Holden
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Product
{
  private:
   string name;
   float basePrice;
   float weight;
   string description;

  public:
   void prompt();
   float getSalesTax();
   float getShippingCost();
   float getTotalPrice();
   void displayAdvertising();
   void displayInventory();
   void displayReceipt();
};

#endif
