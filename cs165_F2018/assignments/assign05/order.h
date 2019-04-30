// File: order.h

#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "customer.h"


// Put your Order class here
class Order
{
  private:
   Product product;
   int quantity;
   Customer customer;
   
   public:
   // Constructors
   Order() {quantity = 0;}
   Order(Product product, int quantity, Customer customer);

   // getters
   Product  getProduct()  {Product val = product; return val;}
   int      getQuantity() {int val = quantity; return val;}
   Customer getCustomer() {Customer val = customer; return val;}
   string   getShippingZip();
   float    getTotalPrice();
   
   // setters
   void setProduct(Product product)    {this->product = product;}
   void setQuantity(int quantity)      {this->quantity = quantity;}
   void setCustomer(Customer customer) {this->customer = customer;}

   // displays
   void displayShippingLabel();
   void displayInformation();
};

#endif
