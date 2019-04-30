/*************************************************************
 * File: flyingObject.cpp
 * Author: Ethan Holden
 *
 * Description: Contains the implementations of the
 *  method bodies for the FlyingObject class.
 *************************************************************/

#include "flyingObject.h"

void FlyingObject :: wrapScreen()
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

void FlyingObject :: advance()
{
   Point p = getPoint();
   Velocity v = getVelocity();
   p.setX(p.getX() + v.getDx());
   p.setY(p.getY() + v.getDy());
   setPoint(p);
}

void FlyingObject :: draw()
{
   
}
