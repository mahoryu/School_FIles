/*************************************************************
 * File: bullet.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the Bullet class.
 *************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include "bullet.h"
#include "flyingObject.h"

class Bullet : public FlyingObject
{
  private:
   float angle;
  public:
   Bullet();
   float getAngle() {return angle;}
   
   void draw();
   void fire(Point point, float angle);
};

#endif
