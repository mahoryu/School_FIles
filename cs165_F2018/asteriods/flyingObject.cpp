#include <iostream>
using namespace std;

#include "flyingObject.h"
#include <cassert>

/******************************************
 * FLYING OBJECT : CONSTRUCTOR
 * Initialize the flying object as alive.
 *****************************************/
FlyingObject :: FlyingObject()
{
   alive = true;
}

/******************************************
 * FLYINGOBJECT : setAngle
 * Sets the angle of the flyingObject.
 *****************************************/
void FlyingObject ::setAngle(float angle)
{
   if (angle < 0)
      angle += 360;
   if (angle > 360)
      angle -= 360;
   this->angle = angle;
}

/******************************************
 * FLYING OBJECT : wrap
 * if the object goes off screen it moves
 * the object to appear on the other side
 * of the screen.
 *****************************************/
void FlyingObject :: wrap()
{
   Point p = getPoint();
   if (p.getY() > 200 || p.getY() < -200)
   {
      p.setX(1 * p.getX());
      p.setY(-1 * p.getY());
      setPoint(p);
   }
   else if (p.getX() > 200 || p.getX() < -200)
   {
      p.setX(-1 * p.getX());
      p.setY(1 * p.getY());
      setPoint(p);
   }
}

/******************************************
 * FLYING OBJECT : advance
 * moves the flying object accross the screen.
 *****************************************/
void FlyingObject :: advance()
{
   point.addX(velocity.getDx());
   point.addY(velocity.getDy());
}
