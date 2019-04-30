/*************************************************************
 * File: standardBird.h
 * Author: Ethan Holden
 *
 * Description: Contains the definition of the StandardBird class.
 *************************************************************/

#ifndef STANDARDBIRD_H
#define STANDARDBIRD_H

#include "bird.h"

class StandardBird : public Bird
{
  public:
   StandardBird();
   virtual int hit();
   virtual void draw();
};

#endif
