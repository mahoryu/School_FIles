#include "ship.h"

// Put your ship methods here

Ship :: Ship()
{
   angle = 0;
   thrusters = false;
   setRadius(10);
}

void Ship :: rotateR()
{
   angle = angle - ROTATE_AMOUNT;
   if (angle >= 360)
      angle -= 360;
   if (angle < 0)
      angle += 360;
}

void Ship :: rotateL()
{
   angle = angle + ROTATE_AMOUNT;
   if (angle >= 360)
      angle -= 360;
   if (angle < 0)
      angle += 360;
}

void Ship :: thrust()
{
   float dX = THRUST_AMOUNT * (-sin(M_PI / 180.0 * angle));
   float dY = THRUST_AMOUNT * (cos(M_PI / 180.0 * angle));
   Velocity v;
   v.setDx(dX + getVelocity().getDx());
   v.setDy(dY + getVelocity().getDy());

   setVelocity(v);
}

void Ship :: draw()
{
   drawShip(getPoint(), getAngle(), getThrusters());
}
