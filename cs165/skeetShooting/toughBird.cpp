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
   setHealth(random(3, 7));
   
   Point* pPoint = new Point;

   pPoint->setX(-200);
   pPoint->setY(random(-200, 200));
   setPoint(*pPoint);

   Velocity* pVel = new Velocity;
   if(getHealth() > 5)
   {
      pVel->setDx(random(2, 5));
      if(pPoint->getY() <= 0)
         pVel->setDy(random(1, 4));
      else
         pVel->setDy(random(-3, 0));
      setVelocity(*pVel);
   }
   else
   {
      pVel->setDx(random(1, 3));
      if(pPoint->getY() <= 0)
         pVel->setDy(random(1, 3));
      else
         pVel->setDy(random(-2, 0));
      setVelocity(*pVel);
   }

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
      return 3;
   }
}
void ToughBird :: draw()
{
   drawToughBird(getPoint(), 15, getHealth());
}
