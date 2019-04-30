/*************************************************************
 * File: bird.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the Bird class.
 *************************************************************/

#ifndef BIRD_H
#define BIRD_H

#include "bird.h"
#include "flyingObject.h"

class Bird : public FlyingObject
{
  public:
   Bird();
   virtual int hit() = 0;
   virtual void draw() = 0;
};

#endif
