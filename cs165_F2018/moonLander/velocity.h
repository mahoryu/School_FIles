/***********************************************************************
 * Header File:
 *    Velocity 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the definition of the Velocity class
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>

/*********************************************
 * VELOCITY
 * Sets the current velocity of the moving
 * object.
 *********************************************/
class Velocity
{
  private:
   float dX;
   float dY;
   
  public:
   Velocity() : dX(0.0), dY(0.0) {}
   Velocity(float dX, float dY);

   float getDx() const {return dX;}
   float getDy() const {return dY;}

   void setDx(float dX) {this->dX = dX;}
   void setDy(float dY) {this->dY = dY;}
};

#endif // VELOCITY_H
