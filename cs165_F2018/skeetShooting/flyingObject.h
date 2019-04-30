/***********************************************************************
 * Header File:
 *    FlyingObject 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the definition of the FlyingObject class
 ************************************************************************/

#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "velocity.h"
#include "point.h"
#include <iostream>

/*********************************************
 * FLYINGOBJECT
 * The base class for all flying objects
 *********************************************/
class FlyingObject
{
  protected:
   Point point;
   Velocity velocity;
   bool alive;
   
  public:
   FlyingObject(); 

   // getters
   Point getPoint()       {return point;}
   Velocity getVelocity() {return velocity;}

   // setters
   void setPoint(Point point)          {this->point = point;}
   void setVelocity(Velocity velocity) {this->velocity = velocity;}

   // check state
   bool isAlive() {return alive;}
   void kill()    {alive = false;}

   // advance
   void advance();
   
};

#endif // FLYINGOBJECT_H
