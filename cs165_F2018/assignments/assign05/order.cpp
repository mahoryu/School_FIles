// File: order.cpp

#include <iostream>
#include <string>
using namespace std;

#include "order.h"

// Constructors

/***************************************************************
 * sets values to those specified.
 ***************************************************************/
Order :: Order(Product product, int quantity, Customer customer)
{
   this->product = product;
   this->quantity = quantity;
   this->customer = customer;
}

// Methods

/***************************************************************
 * returns the zip code from the customer's address.
 ***************************************************************/
string Order :: getShippingZip()
{
   Address address = customer.getAddress();
   string zip = address.getZip();
   return zip;
}

/***************************************************************
 * calculates the total price base on the quantity ordered.
 ***************************************************************/
float Order :: getTotalPrice()
{
   float itemPrice = product.getTotalPrice();
   return (itemPrice * quantity);
}

/***************************************************************
 * displays the shipping label for the order.
 ***************************************************************/
void Order :: displayShippingLabel()
{
   customer.display();
}

/***************************************************************
 * displays the general order details.
 ***************************************************************/
void Order :: displayInformation()
{
   cout << customer.getName() << endl;
   cout << product.getName() << endl;
   cout << "Total Price: $"
        << getTotalPrice() << endl;
}
