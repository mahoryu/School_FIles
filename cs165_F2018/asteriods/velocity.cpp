/***********************************************************************
 * Source File:
 *    Velocity 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the methods of the Velocity class.
 ************************************************************************/

#include <iostream>
using namespace std;

#include "velocity.h"
#include <cassert>

/******************************************
* VELOCITY : CONSTRUCTOR PASS DX, DY
* Initailizes the starting velocity with the passed numbers.
*****************************************/

Velocity :: Velocity(float dX, float dY)
{
   this->dX = dX;
   this->dY = dY;
}
