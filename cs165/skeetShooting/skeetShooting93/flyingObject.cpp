/*************************************************************
 * File: flyingObject.cpp
 * Author: Ethan Holden
 *
 * Description: Contains the implementations of the
 *  method bodies for the FlyingObject class.
 *************************************************************/

#include "flyingObject.h"

void FlyingObject :: advance()
{
   Point p = getPoint();
   Velocity v = getVelocity();
   p.setX(p.getX() + v.getDx());
   p.setY(p.getY() + v.getDy());
   setPoint(p);
}
