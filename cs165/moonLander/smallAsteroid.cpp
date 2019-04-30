/*************************************************************
 * File: smallAsteroid.cpp
 * Author: Ethan Holden
 *
 * Description: Contains the implementations of the
 *  method bodies for the smallAsteroid class.
 *************************************************************/

#include "smallAsteroid.h"

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

SmallAsteroid :: SmallAsteroid()
{
   point = Point(random(-180, 180), random(190, 200));
   velocity.setDx(random(-3.0, 3.0));
   gravity = .05;
   alive = true;
}

void SmallAsteroid :: applyGravity(float gravity)
{
   Velocity v = getVelocity();
   v.setDy(v.getDy() - gravity);
   setVelocity(v);
}

void SmallAsteroid :: advance()
{
   Point p = getPoint();
   Velocity v = getVelocity();
   p.setX(p.getX() + getVelocity().getDx());
   p.setY(p.getY() + getVelocity().getDy());
   setPoint(p);
}

void SmallAsteroid :: draw()
{
   drawSmallAsteroid(getPoint(), 1);
}
