// File: order.cpp

#include "order.h"
#include "product.h"
#include "customer.h"
#include "address.h"

#include <iostream>
#include <string>
using namespace std;

// Put your the method bodies for your order class here
Order :: Order(const Product &product, const int &quantity, 
               const Customer &customer)
{
   this->product = product;
   this->quantity = quantity;
   this->customer = customer;
}

string Order :: getShippingZip() const
{
   return customer.getAddress().getZip();
}

float Order :: getTotalPrice() const
{
   float price = getProduct().getTotalPrice();
   price *= getQuantity();
   return price;
}

void Order :: displayShippingLabel() const
{
   getCustomer().display();
}

void Order :: displayInformation() const
{
   cout << getCustomer().getName() << endl
        << getProduct().getName()  << endl
        << "Total Price: $" << getTotalPrice() << endl;
}
