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
   point = Point(100, 100);
   gravity = .1;
   fuel = 500;
   alive = true;
   landed = false;
}

Point Lander :: getPoint() const
{
   return point;
}

Velocity Lander :: getVelocity() const
{
   return velocity;
}

bool Lander :: isAlive()
{
   return alive;
}

bool Lander :: isLanded()
{
   return landed;
}

int Lander :: getFuel() const
{
   return fuel;
}

bool Lander :: canThrust()
{
   if (fuel > 0)
      return true;
   else
      return false;
}

void Lander :: setLanded(bool landed)
{
   this->landed = landed;
}

void Lander :: setAlive(bool alive)
{
   this->alive = alive;
}

void Lander :: setFuel(int fuel)
{
   this->fuel = fuel;
}

void Lander :: applyGravity(float gravity)
{
}

void Lander :: applyThrustLeft()
{
}

void Lander :: applyThrustRight()
{
}

void Lander :: applyThrustBottom()
{
}

void Lander :: advance()
{
}

void Lander :: draw()
{
   drawLander(getPoint());
}
