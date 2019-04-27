/*************************************************************
 * File: lander.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the lander class.
 *************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"

class Lander
{
  private:
   Point point;
   Velocity velocity;
   float gravity;
   int fuel;
   bool alive;
   bool landed;
  public:
   Lander();
   Point getPoint() const {return point;}
   Velocity getVelocity() const {return velocity;}
   bool isAlive() {return alive;}
   bool isLanded() {return landed;}
   int getFuel() const {return fuel;}
   bool canThrust();

   void setLanded(bool landed) {this->landed = landed;}
   void setAlive(bool alive) {this->alive = alive;}
   void setFuel(int fuel) {this->fuel = fuel;}
   void setVelocity(Velocity velocity) {this->velocity = velocity;}
   void setPoint(Point point) {this->point = point;}

   void applyGravity(float gravity);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();

   void advance();
   void draw();
};

#endif
