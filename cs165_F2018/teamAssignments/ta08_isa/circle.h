#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "point.h"

/***********************************************************
 * Class: Circle
 * Description: Holds a simply integer pair (xCoord, yCoord)
 ***********************************************************/
class Circle : public Point
{
  private:
   float radius;
   

  public:
  Circle() : radius(0) { }
   
   // Getters
   float getRadius() const { return radius; }
   
   // Setters
   void setRadius(float radius) { this->radius = radius; }

   void display() const;
   void promptForCircle();
};

#endif

