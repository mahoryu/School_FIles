/*************************************************************
 * File: lander.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the lander class.
 *************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"

class Lander
{
  private:
   Point point;
   Velocity velocity;
   float gravity;
   int fuel;
   bool alive;
   bool landed;
  public:
   Lander();
   Point getPoint() const;
   Velocity getVelocity() const;
   bool isAlive();
   bool isLanded();
   int getFuel() const;
   bool canThrust();

   void setLanded(bool landed);
   void setAlive(bool alive);
   void setFuel(int fuel);

   void applyGravity(float gravity);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();

   void advance();
   void draw();
};

#endif
