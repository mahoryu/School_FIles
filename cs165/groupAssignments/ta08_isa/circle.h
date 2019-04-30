#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"
#include <iostream>

/***********************************************************
 * Class: Circle
 * Description: Holds an integer set (xCoord, yCoord, radius)
 ***********************************************************/

class Circle : public Point
{
  private:
   float radius;
  public:
   float getRadius() const {return radius;}
   void setRadius(float radius) {this->radius = radius;}

   void promptForCircle();
   void display() const;
};

#endif
