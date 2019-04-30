#include <iostream>
#include "circle.h"

using namespace std;

/***********************************************************
 * Function: Circle :: display
 * Outputs a circle to the screen.
 ***********************************************************/
void Circle :: display() const
{
Point::display();
cout << " - Radius: " << radius;
}

/***********************************************************
 * Function: Circle :: promptForCircle
 * Prompts the user for the coordinates of the circle.
 ***********************************************************/
void Circle :: promptForCircle()
{
Point::promptForPoint();
cout << "Enter radius: ";
cin  >> radius;
}

