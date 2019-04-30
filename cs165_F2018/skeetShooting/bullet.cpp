/***********************************************************************
 * Source File:
 *    Bullet 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the methods of the Bullet class.
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

#include "bullet.h"
#include <cassert>

#define BULLET_SPEED 10.0

/******************************************
 * BULLET : CONSTRUCTOR
 * Initialize the bullet to the default position
 *****************************************/
Bullet :: Bullet()
{
   point.setX(200);
   point.setY(-200);
}

/******************************************
 * BULLET : draw
 * Draws the bullet on the screen.
 *****************************************/
void Bullet :: draw()
{
   drawDot(point);
}

/******************************************
 * BULLET : fire
 * Fires the bullet at the passed angle from the passed point.
 *****************************************/
void Bullet :: fire(Point point, float angle)
{
   float dx = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
   float dy = BULLET_SPEED * (sin(M_PI / 180.0 * angle));

   velocity.setDx(dx);
   velocity.setDy(dy);
   this->point = point;
}
