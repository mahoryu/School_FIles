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
   float radius;
  public:
   FlyingObject() : alive(true) {}
   Point getPoint() const {return point;}
   Velocity getVelocity() const {return velocity;}
   bool isAlive() const {return alive;}
   int getRadius() const {return radius;}

   void setPoint(Point point) {this->point = point;}
   void setVelocity(Velocity velocity) {this->velocity = velocity;}
   void setAlive() {alive = true;}
   void kill() {alive = false;}
   void setRadius(float radius) {this->radius = radius;}

   void wrapScreen();

   virtual void advance();
   virtual void draw();
};

#endif
