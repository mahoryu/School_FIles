#include "rocks.h"

// Put your Rock methods here
Rock :: Rock()
{
   setAlive();
   angle = random(0, 360);
   
   Point* pPoint = new Point;

   pPoint->setX(random(-200, 200));
   pPoint->setY(random(-200, 200));
   setPoint(*pPoint);

   Velocity* pVel = new Velocity;
   pVel->setDx(-cos(M_PI / 180.0 * angle));
   pVel->setDy(sin(M_PI / 180.0 * angle));   
   setVelocity(*pVel);

   delete pPoint;
   pPoint = NULL;
   delete pVel;
   pVel = NULL;
}

int Rock :: hit()
{
   kill();
   
   return 1;
}


/*******************
 * BigRock methods
 *******************/
BigRock :: BigRock()
{
   setRadius(BIG_ROCK_SIZE);
   setAlive();
}

int BigRock :: hit()
{
   kill();
   // Add the make medium rocks.

   return 1;
}

void BigRock :: draw()
{
   drawLargeAsteroid(getPoint(), BIG_ROCK_SPIN);
}

/*******************
 * MediumRock methods
 *******************/
MediumRock :: MediumRock()
{
   setRadius(MEDIUM_ROCK_SIZE);
   setAlive();
}

MediumRock :: MediumRock(Velocity velocity, Point point)
{
   setRadius(MEDIUM_ROCK_SIZE);
   setVelocity(velocity);
   setPoint(point);
}

int MediumRock :: hit()
{
   kill();
   // Add the make small rocks.

   return 1;
}

void MediumRock :: draw()
{
   drawMediumAsteroid(getPoint(), MEDIUM_ROCK_SPIN);
}

/*******************
 * SmallRock methods
 *******************/
SmallRock :: SmallRock()
{
   setRadius(SMALL_ROCK_SIZE);
   setAlive();
}

SmallRock :: SmallRock(Velocity velocity, Point point)
{
   setRadius(SMALL_ROCK_SIZE);
   setVelocity(velocity);
   setPoint(point);
}

int SmallRock :: hit()
{
   kill();

   return 1;
}

void SmallRock :: draw()
{
   drawSmallAsteroid(getPoint(), SMALL_ROCK_SPIN);
}
