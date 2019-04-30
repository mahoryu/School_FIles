#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10
#define SHIELD_SIZE 15

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "flyingObject.h"

/*********************************************
 * SHIP
 * Class for the ship object.
 *********************************************/
class Ship : public FlyingObject
{
  private:
   bool thrusters;
   int shieldHP;
   
  public:
   Ship();
   
   // setters
   void setThrusters(bool thrusters) {this->thrusters = thrusters;}
   
   // getters
   bool getThrusters() const {return thrusters;}
   
   // Movement
   void rotateR();
   void rotateL();
   void thrust();
   void bounce();
   
   // Shield
   void addShieldHP();
   void hit();
   
   void draw();
};

#endif /* ship_h */
