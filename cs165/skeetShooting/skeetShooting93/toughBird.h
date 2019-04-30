/*************************************************************
 * File: toughBird.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the ToughBird class.
 *************************************************************/

#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H

#include "bird.h"

class ToughBird : public Bird
{
  private:
   int health;
  public:
   ToughBird();
   int getHealth() { return health; }
   void setHealth(int health) { this->health = health; }
   virtual int hit();
   virtual void draw();
};

#endif
