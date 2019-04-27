/*************************************************************
 * File: lander.cpp
 * Author: Ethan Holden
 *
 * Description: Contains the implementations of the
 *  method bodies for the lander class.
 *************************************************************/

#include "lander.h"

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

Lander :: Lander()
{
   point = Point(random(-180, 180), random(150, 190));
   gravity = .1;
   fuel = 500;
   alive = true;
   landed = false;
}

bool Lander :: canThrust()
{
   if (fuel > 0 && alive)
      return true;
   else
      return false;
}

void Lander :: applyGravity(float gravity)
{
   Velocity v = getVelocity();
   v.setDy(v.getDy() - gravity);
   setVelocity(v);
}

void Lander :: applyThrustLeft()
{
   Velocity v = getVelocity();
   v.setDx(v.getDx() + .1);
   setVelocity(v);

   setFuel(getFuel() - 1);
}

void Lander :: applyThrustRight()
{
   Velocity v = getVelocity();
   v.setDx(v.getDx() - .1);
   setVelocity(v);
   
   setFuel(getFuel() - 1);
}

void Lander :: applyThrustBottom()
{
   Velocity v = getVelocity();
   v.setDy(v.getDy() + .3);
   setVelocity(v);
   
   setFuel(getFuel() - 3);
}

void Lander :: advance()
{
   Point p = getPoint();
   Velocity v = getVelocity();
   p.setX(p.getX() + getVelocity().getDx());
   p.setY(p.getY() + getVelocity().getDy());
   setPoint(p);
}

void Lander :: draw()
{
   drawLander(getPoint());
}
