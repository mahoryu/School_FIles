/***********************************************************************
 * Header File:
 *    Bullet 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the definition of the Bullet class
 ************************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include "flyingObject.h"
#include "uiDraw.h"
#include <iostream>

/*********************************************
 * BULLET
 * Class for the bullet objects.
 *********************************************/
class Bullet : public FlyingObject
{
  private:
   float angle;
   
  public:
   Bullet();
   void draw();
   void fire(Point point, float angle);
};

#endif // BULLET_H
