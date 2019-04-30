/***********************************************************************
 * Source File:
 *    Lander 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the methods of the Lander class.
 ************************************************************************/

#include <iostream>
using namespace std;

#include "lander.h"
#include "uiDraw.h"
#include <cassert>

#define RAND_START_X random(-200, 200)

Lander :: Lander()
{
   //set random starting point
   position.setX(RAND_START_X);
   position.setY(200);

   //set velocity based on starting point
   if (RAND_START_X < 0)
      velocity.setDx(-0.3);
   else if (RAND_START_X > 0)
      velocity.setDx(0.3);
   else
      velocity.setDx(0);
   velocity.setDy(0);

   //set other values
   gravity = 0.1;
   alive = true;
   landed = false;
}

bool Lander :: canThrust()
{
   if (fuel > 0 && alive == true && landed == false)
      return true;
   else
      return false;
}

void Lander :: applyGravity(float gravity)
{
   velocity.setDy(velocity.getDy() - gravity);
}

void Lander :: applyThrustLeft()
{
   velocity.setDx(velocity.getDx() + 0.1);
   fuel -= 1;
}

void Lander :: applyThrustRight()
{
   velocity.setDx(velocity.getDx() - 0.1);
   fuel -= 1;
}

void Lander :: applyThrustBottom()
{
   velocity.setDy(velocity.getDy() + 0.3);
   fuel -= 3;
}

void Lander :: advance()
{ 
   position.setX(position.getX() + velocity.getDx());
   position.setY(position.getY() + velocity.getDy());
}

void Lander :: draw()
{
   drawLander(getPoint());
}
