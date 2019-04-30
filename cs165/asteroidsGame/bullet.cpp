/*************************************************************
 * File: bullet.cpp
 * Author: Ethan Holden
 *
 * Description: Contains the implementations of the
 *  method bodies for the bullet class.
 *************************************************************/

#include "bullet.h"
#include <cmath>

#define BULLET_SPEED 10.0

Bullet :: Bullet()
{
   setAlive();
   setRadius(1);
   lifeSpan = 40;
}

void Bullet :: advance()
{
   FlyingObject :: advance();

   lifeSpan--;
   if (lifeSpan <= 0)
      kill();
}

void Bullet :: draw()
{
   drawDot(getPoint());
}

void Bullet :: fire(Point point, float angle, Velocity velocity)
{
   setPoint(point);
   setVelocity(velocity);
   this->angle = angle;
   
   float dX = BULLET_SPEED * (-sin(M_PI / 180.0 * angle));
   float dY = BULLET_SPEED * (cos(M_PI / 180.0 * angle));
   Velocity v;
   v.setDx(dX + velocity.getDx());
   v.setDy(dY + velocity.getDy());
   
   setVelocity(v);
}

