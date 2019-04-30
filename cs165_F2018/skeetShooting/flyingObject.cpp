/***********************************************************************
 * Source File:
 *    FlyingObject 
 * Author:
 *    Ethan Holden
 * Summary:
 *    Contains the methods of the FlyingObject class.
 ************************************************************************/

#include <iostream>
using namespace std;

#include "flyingObject.h"
#include <cassert>

/******************************************
 * FLYING OBJECT : CONSTRUCTOR 
 * Initialize the flying object as alive.
 *****************************************/
FlyingObject :: FlyingObject()
{
   alive = true;
}

/******************************************
 * FLYING OBJECT : advance
 * moves the flying object accross the screen.
 *****************************************/
void FlyingObject :: advance()
{
   point.addX(velocity.getDx());
   point.addY(velocity.getDy());
}
