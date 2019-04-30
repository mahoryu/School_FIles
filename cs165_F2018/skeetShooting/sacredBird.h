/***********************************************************************
 * Header File:
 *    SacredBird 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the definition of the SacredBird class
 ************************************************************************/

#ifndef SACREDBIRD_H
#define SACREDBIRD_H

#include "bird.h"
#include <iostream>

/*********************************************
 * SACREDBIRD
 * Class for the sacredBird objects.
 *********************************************/
class SacredBird : public Bird
{
  public:
   SacredBird();
   virtual int hit();
   virtual void draw();
};

#endif // SACREDBIRD_H
