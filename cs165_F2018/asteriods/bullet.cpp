#include <iostream>
#include <cmath>
using namespace std;

#include "bullet.h"
#include <cassert>

/******************************************
 * BULLET : CONSTRUCTOR
 * Initialize the bullet to the default position
 *****************************************/
Bullet :: Bullet()
{
   point.setX(0);
   point.setY(0);
   lifeSpan = 0;
   setRadius(1);
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
void Bullet :: fire(Point point, float angle, Velocity shipV)
{
   setPoint(point);
   setAngle(angle);
   
   float dx = BULLET_SPEED * (-sin(M_PI / 180.0 * angle));
   float dy = BULLET_SPEED * (cos(M_PI / 180.0 * angle));
   velocity.setDx(dx + shipV.getDx());
   velocity.setDy(dy + shipV.getDy());
}

/******************************************
 * Bullet : advance
 * moves the bullet accross the screen.
 *****************************************/
void Bullet :: advance()
{
   point.addX(velocity.getDx());
   point.addY(velocity.getDy());

   lifeSpan++;
   if (lifeSpan == BULLET_LIFE)
      kill();
}
