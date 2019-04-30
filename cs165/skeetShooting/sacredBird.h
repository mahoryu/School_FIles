/*************************************************************
 * File: sacredBird.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the SacredBird class.
 *************************************************************/

#ifndef SACREDBIRD_H
#define SACREDBIRD_H

#include "bird.h"

class SacredBird : public Bird
{
  public:
   SacredBird();
   virtual int hit();
   virtual void draw();
};

#endif
