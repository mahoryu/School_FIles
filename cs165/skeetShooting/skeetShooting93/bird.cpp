/*************************************************************
 * File: bird.cpp
 * Author: Ethan Holden
 *
 * Description: Contains the implementations of the
 *  method bodies for the Bird class.
 *************************************************************/

#include "bird.h"

Bird :: Bird()
{
   setAlive();
   
   Point* pPoint = new Point;

   pPoint->setX(-200);
   pPoint->setY(random(-200, 200));
   setPoint(*pPoint);
      
   Velocity* pVel = new Velocity;
   pVel->setDx(random(3, 7));
   if(pPoint->getY() <= 0)
      pVel->setDy(random(1, 5));
   else
      pVel->setDy(random(-4, 0));
   setVelocity(*pVel);

   delete pPoint;
   pPoint = NULL;
   delete pVel;
   pVel = NULL;
   
}


