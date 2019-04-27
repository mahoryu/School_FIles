/*************************************************************
 * File: velocity.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the velocity class.
 *************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
  private:
   float dX;
   float dY;
  public:
   Velocity();
   Velocity(float dX, float dY);
   float getDx() const {return dX;}
   float getDy() const {return dY;}
   void setDx(float dX) {this->dX = dX;}
   void setDy(float dY) {this->dY = dY;}
};

#endif
