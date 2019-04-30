/***********************************************************************
 * Source File:
 *    StandardBird 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the methods of the StandardBird class.
 ************************************************************************/

#include <iostream>
using namespace std;

#include "standardBird.h"
#include <cassert>

/******************************************
 * STANDARD BIRD : CONSTRUCTOR
 * Initializes the bird at a random location
 *****************************************/
StandardBird :: StandardBird()
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
 * STANDARD BIRD : hit
 * Reduces the bird's health and kills it if it is at 0 health.
 *****************************************/
int StandardBird :: hit()
{
   health -= 1;
   if (health <= 0)
      kill();

   return 1;
}

/******************************************
 * STANDARD BIRD : draw
 * Draws the standard bird on the screen.
 *****************************************/
void StandardBird :: draw()
{
   drawCircle(point, 15);
}
