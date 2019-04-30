#ifndef flyingObject_h
#define flyingObject_h

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
   int radius;
   float angle;
   
  public:
   FlyingObject();

   // getters
   Point getPoint()       const {return point;}
   Velocity getVelocity() const {return velocity;}
   int getRadius()        const {return radius;}
   int getAngle()         const {return angle;}

   // setters
   void setPoint(Point point)          {this->point = point;}
   void setVelocity(Velocity velocity) {this->velocity = velocity;}
   void setRadius(int radius)          {this->radius = radius;}
   void setAngle(float angle);
   
   // check state
   bool isAlive() {return alive;}
   void kill()    {alive = false;}
   void wrap();

   // advance
   virtual void advance();
   
};

#endif /* flyingObject_h */
