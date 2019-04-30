/*************************************************************
 * File: bossBird.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the BossBird class.
 *************************************************************/

#ifndef BOSSBIRD_H
#define BOSSBIRD_H

#include "bird.h"

class BossBird : public Bird
{
  private:
   int health;
   int dCount;
  public:
   BossBird();
   int getHealth() { return health; }
   void setHealth(int health) { this->health = health; }
   int getDCount() { return dCount; }
   void setDCount(int dCount) { this->dCount = dCount; }
   virtual int hit();
   virtual void draw();
   virtual void advance();
};

#endif
