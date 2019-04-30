/*************************************************************
 * File: flyingObject.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the FlyingObject class.
 *************************************************************/

#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

#include <iostream>
using namespace std;

class FlyingObject
{
  private:
   Point point;
   Velocity velocity;
   bool alive;
  public:
   FlyingObject() : alive(true) {}
   Point getPoint() {return point;}
   Velocity getVelocity() {return velocity;}
   bool isAlive() {return alive;}

   void setPoint(Point point) {this->point = point;}
   void setVelocity(Velocity velocity) {this->velocity = velocity;}
   void setAlive() {alive = true;}
   void kill() {alive = false;}

   void advance();
};

#endif
