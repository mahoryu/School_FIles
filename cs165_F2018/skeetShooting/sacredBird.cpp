/***********************************************************************
 * Source File:
 *    SacredBird 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the methods of the SacredBird class.
 ************************************************************************/

#include <iostream>
using namespace std;

#include "sacredBird.h"
#include <cassert>

/******************************************
 * SACRED BIRD : CONSTRUCTOR
 * Initialize the sacred bird object in a random location
 *****************************************/
SacredBird :: SacredBird()
{
   point.setX(-200);
   int ran = random(-200, 200);
   point.setY(ran);

   if (ran > 0)
      velocity.setDy(random(-4.0, 0.0));
   else
      velocity.setDy(random(0.0, 4.0));
   velocity.setDx(random(3.0, 6.0));

   health = 1;
}

/******************************************
 * SACRED BIRD : hit
 * Reduces the bird's health and kills it if it is at 0 health.
 *****************************************/
int SacredBird :: hit()
{
   health -= 1;
   if (health <= 0)
      kill();

   return -10;
}

/******************************************
 * SACRED BIRD : draw
 * Draws the sacred bird on the screen.
 *****************************************/
void SacredBird :: draw()
{
   drawSacredBird(point, 15);
   drawRainbowCircle(point, 15);
}
