/*************************************************************
 * File: standardBird.cpp
 * Author: Ethan Holden
 *
 * Description: Contains the implementations of the
 *  method bodies for the StandardBird class.
 *************************************************************/

#include "standardBird.h"

StandardBird :: StandardBird()
{
   setAlive();
}

int StandardBird :: hit()
{
   kill();
   return 1;
}

void StandardBird :: draw()
{
   drawCircle(getPoint(), 15);
}
