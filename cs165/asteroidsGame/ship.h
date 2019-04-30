#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "flyingObject.h"

// Put your Ship class here
class Ship : public FlyingObject
{
  private:
   float angle;
   bool thrusters;
  public:
   Ship();
   void rotateR();
   void rotateL();
   void thrust();
   
   void setThrusters(bool thrusters) {this->thrusters = thrusters;}
   
   bool getThrusters() { return thrusters; }
   float getAngle() { return angle; }

   virtual void draw();
};

#endif /* ship_h */
