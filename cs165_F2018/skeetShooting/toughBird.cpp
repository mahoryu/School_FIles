/***********************************************************************
 * Source File:
 *    ToughBird 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the methods of the ToughBird class.
 ************************************************************************/

#include <iostream>
using namespace std;

#include "toughBird.h"
#include <cassert>

/******************************************
 * TOUGH BIRD : CONSTRUCTOR
 * Initializes the bird at a random location
 *****************************************/
ToughBird :: ToughBird()
{
   point.setX(-200);
   int ran = random(-200, 200);
   point.setY(ran);

   if (ran > 0)
      velocity.setDy(random(-3.0, 0.0));
   else
      velocity.setDy(random(0.0, 3.0));
   velocity.setDx(random(2.0, 4.0));
   health = 3;
}

/******************************************
 * STANDARD BIRD : hit
 * Reduces the bird's health and kills it if it is at 0 health.
 *****************************************/
int ToughBird :: hit()
{
   health -= 1;
   if (health <= 0)
   {
      kill();
      return 3;
   }
   
   return 1;
}

/******************************************
* TOUGH BIRD : draw
* Draws the tough bird on the screen.
*****************************************/
void ToughBird :: draw()
{
   drawToughBird(point, 15, health);
}
