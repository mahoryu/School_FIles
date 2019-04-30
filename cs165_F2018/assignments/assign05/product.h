/***************************************************************
 * File: product.h
 * Author: Ethan Holden
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
  private:
   string name;
   float basePrice;
   float weight;
   string description;

  public:
   //Constructors
   Product();
   Product(string name, string description, float basePrice, float weight);

   //getters
   string getName()        {string val = name; return val;}
   string getDescription() {string val = description; return val;}
   float  getBasePrice()   {float val = basePrice; return val;}
   float  getWeight()      {float val = weight; return val;}
   
   //setters
   void setName(string name)               {this->name = name;}
   void setDescription(string description) {this->description = description;}
   void setBasePrice(float basePrice)      {this->basePrice = basePrice;}
   void setWeight(float weight)            {this->weight = weight;}
   
   //calculations
   float getSalesTax();
   float getShippingCost();
   float getTotalPrice();

   //display
   void displayAdvertising();
   void displayInventory();
   void displayReceipt();
};

#endif
