/***********************************************************************
 * Header File:
 *    ToughBird 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the definition of the ToughBird class
 ************************************************************************/

#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H

#include "bird.h"
#include <iostream>

/*********************************************
 * TOUGHBIRD
 * Class for the ToughBird objects.
 *********************************************/
class ToughBird : public Bird
{
  public:
   ToughBird();
   virtual int hit();
   virtual void draw();
};

#endif // TOUGHBIRD_H
