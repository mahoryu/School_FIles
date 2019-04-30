#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "flyingObject.h"
#include "uiDraw.h"
#include <iostream>

/*********************************************
 * BULLET
 * Class for the bullet objects.
 *********************************************/
class Bullet : public FlyingObject
{
  private:
   int lifeSpan;
   
  public:
   Bullet();
   void draw();
   void fire(Point point, float angle, Velocity shipV);
   virtual void advance();
};

#endif /* bullet_h */
