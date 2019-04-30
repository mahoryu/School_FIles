/*************************************************************
 * File: smallAsteroid.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the smallAsteroid
 * class.
 *************************************************************/

#ifndef SMALLASTEROID_H
#define SMALLASTEROID_H

#include "point.h"
#include "velocity.h"

class SmallAsteroid
{
  private:
   Point point;
   Velocity velocity;
   float gravity;
   bool alive;
  public:
   SmallAsteroid();
   Point getPoint() const {return point;}
   Velocity getVelocity() const {return velocity;}
   bool isAlive() {return alive;}
  
   void setVelocity(Velocity velocity) {this->velocity = velocity;}
   void setPoint(Point point) {this->point = point;}
   void setAlive(bool alive) {this->alive = alive;}
   
   void applyGravity(float gravity);
   
   void advance();
   void draw();
};

#endif
