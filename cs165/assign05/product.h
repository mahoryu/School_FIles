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
   string getName() const {return name;}
   string getDescription() const {return description;}
   float getBasePrice() const {return bPrice;}
   float getWeight() const {return weight;}
   void setName(string name) {this->name = name;}
   void setDescription(string description)
   {this->description = description;}
   void setBasePrice(float bPrice) {this->bPrice = bPrice;}
   void setWeight(float weight) {this->weight = weight;}
   void displayAdvertising() const;
   void displayInventory() const;
   void displayReceipt() const;
   Product();
   Product(const string &name, const string &description, 
           const float &bPrice, const float &weight);
   float getSalesTax() const;
   float getShippingCost() const;
   float getTotalPrice() const;
  private:
   string name;
   string description;
   float bPrice;
   float weight;
	
};

#endif
