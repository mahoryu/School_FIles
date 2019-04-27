// File: customer.cpp

#include "customer.h"
#include "address.h"

#include <iostream>
#include <string>
using namespace std;

// Put the method bodies for your customer class here
Customer :: Customer()
{
	setName("unspecified");
}

Customer :: Customer(string name, Address address)
{
	this->name = name;
	this->address = address;
}

void Customer :: display() const
{
	cout << getName() << endl;
	Address cAdd = getAddress();
	cAdd.display();
}
