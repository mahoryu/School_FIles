#include "ship.h"
#include "uiDraw.h"
#include <cmath>
using namespace std;

/******************************************
 * SHIP : CONSTRUCTOR
 * Initialize the ship starting angle with
 * thrusters off.
 *****************************************/
Ship :: Ship()
{
   setRadius(SHIELD_SIZE);
   angle = 0;
   thrusters = false;
   shieldHP = 1;
}

/******************************************
 * SHIP : ROTATE_R
 * Turns the ship to the right.
 *****************************************/
void Ship :: rotateR()
{
   setAngle(angle - ROTATE_AMOUNT);
}

/******************************************
 * SHIP : ROTATE_L
 * Turns the ship to the left.
 *****************************************/
void Ship :: rotateL()
{
   setAngle(angle + ROTATE_AMOUNT);
}

/******************************************
 * SHIP : THRUST
 * Applies the thrust to the ship's movement.
 *****************************************/
void Ship :: thrust()
{
   float dx = THRUST_AMOUNT * (-sin(M_PI / 180.0 * angle));
   float dy = THRUST_AMOUNT * (cos(M_PI / 180.0 * angle));
   velocity.setDx(dx + velocity.getDx());
   velocity.setDy(dy + velocity.getDy());
}

/******************************************
 * SHIP : BOUNCE
 * Bounces the ship into the opposite direction.
 *****************************************/
void Ship :: bounce()
{
   setVelocity(Velocity(-velocity.getDx(), -velocity.getDy()));
}

/******************************************
 * SHIP : ADD_SHIELD_HP
 * Adds HP to the ship's shield.
 *****************************************/
void Ship :: addShieldHP()
{
   shieldHP++;
   if (shieldHP > 0)
      setRadius(SHIELD_SIZE);
}

/******************************************
 * SHIP : HIT
 * controls what happens when the ship is hit.
 *****************************************/
void Ship :: hit()
{
   if (shieldHP == 0)
      kill();
   else
      shieldHP--;
   if (shieldHP == 0)
      setRadius(SHIP_SIZE);
}

/******************************************
 * SHIP : DRAW
 * Draws the ship on the screen.
 *****************************************/
void Ship :: draw()
{
   drawShip(point, angle, thrusters);

   if (shieldHP > 2)
      drawCircle(point, SHIELD_SIZE, 'G');
   else if (shieldHP > 1)
      drawCircle(point, SHIELD_SIZE, 'B');
   else if (shieldHP == 1)
      drawCircle(point, SHIELD_SIZE, 'R');
}
