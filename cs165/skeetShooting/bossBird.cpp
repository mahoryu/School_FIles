/*************************************************************
 * File: bossBird.cpp
 * Author: Ethan Holden
 *
 * Description: Contains the implementations of the
 *  method bodies for the BossBird class.
 *************************************************************/

#include "bossBird.h"

BossBird :: BossBird()
{
   setAlive();
   // set Health
   setHealth(random(20, 31));
   // set how long the bird will continue in one direction
   setDCount(random(10, 41));

   Point* pPoint = new Point;
   pPoint->setX(-200);
   pPoint->setY(random(-100, 101));
   setPoint(*pPoint);

   Velocity* pVel = new Velocity;
   pVel->setDx(.75);
   if(pPoint->getY() <= 0)
      pVel->setDy(random(0, 1));
   else
      pVel->setDy(random(-1, 1));
   setVelocity(*pVel);

   delete pPoint;
   pPoint = NULL;
   delete pVel;
   pVel = NULL;
}

int BossBird :: hit()
{
   if (getHealth() > 1)
   {
      setHealth(getHealth() - 1);
      return 1;
   }
   else
   {
      kill();
      return 11;
   }
}
void BossBird :: draw()
{
   drawToughBird(getPoint(), 15, getHealth());
   drawSacredBird(getPoint(), 30);
}

void BossBird :: advance()
{
   // advance the bird
   Point p = getPoint();
   Velocity v = getVelocity();
   p.setX(p.getX() + v.getDx());
   p.setY(p.getY() + v.getDy());
   setPoint(p);

   //reduce the count
   setDCount(getDCount() - 1);

   if(getDCount() == 0)
   {
      Velocity* pVel = new Velocity;
      pVel->setDy(random(-3, 4));
      pVel->setDx(.75);
      setVelocity(*pVel);
      
      delete pVel;
      pVel = NULL;

      setDCount(random(10, 41));
   }
}
