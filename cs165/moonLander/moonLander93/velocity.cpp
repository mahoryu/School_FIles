/*************************************************************
 * File: velocity.cpp
 * Author: Ethan Holden
 *
 * Description: Contains the implementations of the
 *  method bodies for the velocity class.
 *************************************************************/

#include "velocity.h"

Velocity :: Velocity()
{
   dX = 1;
   dY = -.1;
}

Velocity :: Velocity(float dX, float dY)
{
   this->dX = dX;
   this->dY = dY;
}
