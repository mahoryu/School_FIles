/***********************************************************************
 * Header File:
 *    StandardBird 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the definition of the StandardBird class
 ************************************************************************/

#ifndef STANDARDBIRD_H
#define STANDARDBIRD_H

#include "bird.h"
#include <iostream>

/*********************************************
 * STANDARDBIRD
 * Class for the standardBird objects.
 *********************************************/
class StandardBird : public Bird
{
  public:
   StandardBird();
   virtual int hit();
   virtual void draw();
};

#endif // STANDARDBIRD_H
