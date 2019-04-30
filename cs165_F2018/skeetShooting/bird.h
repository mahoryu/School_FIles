/***********************************************************************
 * Header File:
 *    Bird 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the definition of the Bird class
 ************************************************************************/

#ifndef BIRD_H
#define BIRD_H

#include "flyingObject.h"
#include "uiDraw.h"
#include <iostream>

/*********************************************
 * BIRD
 * Class for the bird objects.
 *********************************************/
class Bird : public FlyingObject
{
  protected:
   int health;
  public:
   Bird();
   virtual int hit() = 0;
   virtual void draw() = 0;
};

#endif // BIRD_H
