#include "rocks.h"
#include "uiDraw.h"
#include <cmath>
using namespace std;

/*********************************************
 * ROCK : HIT
 * Sets the action for when the rock is hit
 *********************************************/
int Rock :: hit()
{
   kill();
   return 100;
}

/*********************************************
 * BIG_ROCK : CONSTRUCTOR
 * Sets the intitial conditions for the big rock.
 *********************************************/
BigRock :: BigRock()
{
   setRadius(BIG_ROCK_SIZE);
   alive = true;
   setAngle(random(0, 360));
   
   setPoint(Point(random(-200, 200),
                  random(-200, 200)));
   setVelocity(Velocity(-cos(M_PI / 180.0 * getAngle()),
                        sin(M_PI / 180.0 * getAngle())));
}

/*********************************************
 * BIG_ROCK : DRAW
 * Draws a big rock on the screen
 *********************************************/
void BigRock :: draw()
{
   drawLargeAsteroid(point, BIG_ROCK_SPIN);
}

/***********************************************************************************/

/*********************************************
 * MEDIUM_ROCK : NON-DEFAULT CONSTRUCTOR
 * Sets the intitial conditions for the medium rock.
 *********************************************/
MediumRock :: MediumRock(Velocity v, Point p)
{
   setRadius(MEDIUM_ROCK_SIZE);
   setVelocity(v);
   setPoint(p);
}

/*********************************************
 * MEDIUM_ROCK : DRAW
 * Draws a medium rock on the screen
 *********************************************/
void MediumRock :: draw()
{
   drawMediumAsteroid(point, MEDIUM_ROCK_SPIN);
}

/***********************************************************************************/

/*********************************************
 * SMALL_ROCK : NON-DEFAULT CONSTRUCTOR
 * Sets the intitial conditions for the small rock.
 *********************************************/
SmallRock :: SmallRock(Velocity v, Point p)
{
   setRadius(SMALL_ROCK_SIZE);
   setVelocity(v);
   setPoint(p);
   
   int num = random(0,9);
   switch (num)
   {
      case 5:
         special = true;
         break;
      default:
         special = false;
   }
}

/*********************************************
 * SMALL_ROCK : HIT
 * Sets the action for when a small rock is hit
 *********************************************/
int SmallRock :: hit()
{
   kill();
   if (special)
      return 150;
   else
      return 100;
}

/*********************************************
 * SMALL_ROCK : DRAW
 * Draws a small rock on the screen
 *********************************************/
void SmallRock :: draw()
{
   if (special)
      drawSpecialSmallAsteroid (point, SMALL_ROCK_SPIN);
   else
      drawSmallAsteroid(point, SMALL_ROCK_SPIN);
}


