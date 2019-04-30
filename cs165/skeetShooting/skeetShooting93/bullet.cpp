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
   setPoint(Point(10, -10));
}

void Bullet :: draw()
{
   drawDot(getPoint());
}

void Bullet :: fire(Point point, float angle)
{
   setPoint(point);
   this->angle = angle;

   float dX = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
   float dY = BULLET_SPEED * (sin(M_PI / 180.0 * angle));
   Velocity v;
   v.setDx(dX);
   v.setDy(dY);
   
   setVelocity(v);
}

