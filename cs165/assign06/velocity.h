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
   float getDx() const;
   float getDy() const;
   void setDx(float dX);
   void setDy(float dY);   
};

#endif
