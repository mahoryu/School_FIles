/*************************************************************
 * File: bullet.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the Bullet class.
 *************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include "flyingObject.h"

class Bullet : public FlyingObject
{
  private:
   float angle;
   int lifeSpan;
  public:
   Bullet();
   float getAngle() {return angle;}

   virtual void advance();
   virtual void draw();
   void fire(Point point, float angle, Velocity velocity);
};

#endif
