/*************************************************************
 * File: toughBird.cpp
 * Author: Ethan Holden
 *
 * Description: Contains the implementations of the
 *  method bodies for the ToughBird class.
 *************************************************************/

#include "toughBird.h"

ToughBird :: ToughBird()
{
   setAlive();
   setHealth(3);
   
   Point* pPoint = new Point;

   pPoint->setX(-200);
   pPoint->setY(random(-200, 200));
   setPoint(*pPoint);

   Velocity* pVel = new Velocity;
   pVel->setDx(random(2, 5));
   if(pPoint->getY() <= 0)
      pVel->setDy(random(1, 4));
   else
      pVel->setDy(random(-3, 0));
   setVelocity(*pVel);

   delete pPoint;
   pPoint = NULL;
   delete pVel;
   pVel = NULL;
}

int ToughBird :: hit()
{
   if (getHealth() > 1)
   {
      setHealth(getHealth() - 1);
      return 1;
   }
   else
   {
      kill();
      return 2;
   }
}
void ToughBird :: draw()
{
   drawToughBird(getPoint(), 15, getHealth());
}
