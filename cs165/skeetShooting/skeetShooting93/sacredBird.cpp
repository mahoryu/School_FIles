/*************************************************************
 * File: sacredBird.cpp
 * Author: Ethan Holden
 *
 * Description: Contains the implementations of the
 *  method bodies for the SacredBird class.
 *************************************************************/

#include "sacredBird.h"

SacredBird :: SacredBird()
{
   setAlive();
}

int SacredBird :: hit()
{
   kill();
   return -10;
}

void SacredBird :: draw()
{
   drawSacredBird(getPoint(), 15);
}
