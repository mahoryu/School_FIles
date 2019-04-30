/***************************************************************
 * File: product.h
 * Author: Ethan Holden
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// put your class definition here
class Product
{
  public:
    void prompt();
    void displayAd();
    void displayInv();
    void displayReceipt();
  private:
  	string name;
    string description;
    float bPrice;
    float weight;
    float getSalesTax();
    float getShippingCost();
    float getTotalPrice();
    
};

#endif
