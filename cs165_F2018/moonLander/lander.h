/***********************************************************************
 * Header File:
 *    Lander 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contaions the definition of the Lander class.
 ************************************************************************/


#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"

/*********************************************
 * LANDER
 * The class that sets the information about
 * the lander itself.
 *********************************************/
class Lander
{
  private:
   Point position;
   Velocity velocity;
   float gravity;
   int fuel;
   bool alive;
   bool landed;
   
  public:
   Lander();
   Point getPoint()       const {return position;}
   Velocity getVelocity() const {return velocity;}
   bool isAlive()         const {return alive;}
   bool isLanded()        const {return landed;}
   int getFuel()          const {return fuel;}
   bool canThrust();

   void setLanded(bool landed) {this->landed = landed;}
   void setAlive(bool alive)   {this->alive = alive;}
   void setFuel(int fuel)      {this->fuel = fuel;}

   void applyGravity(float gravity);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();

   void advance();
   void draw();
};

#endif // LANDER_H
