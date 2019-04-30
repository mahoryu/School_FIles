/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ground.h"
#include "lander.h"

/******************************************
 * GAME :: JUST LANDED
 * Did we land successfully?
 ******************************************/
bool Game :: justLanded() const
{
   bool landed = false;
   
   Point platformCenter = ground.getPlatformPosition();
   int width = ground.getPlatformWidth();

   float xDiff = lander.getPoint().getX() - platformCenter.getX();
   float yDiff = lander.getPoint().getY() - platformCenter.getY();

   float margin = width / 2.0;
   
   if (fabs(xDiff) < margin)
   {
      // between edges
      
      if (yDiff < 4 && yDiff >= 0)
      {
         // right above it
         
         if (fabs(lander.getVelocity().getDx()) < 3 && fabs(lander.getVelocity().getDy()) < 3)
         {
            // we're there!
            landed = true;
         }
      }
   }
   
   return landed;
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if (lander.isAlive() && !lander.isLanded())
   {
      // advance the lander
      lander.applyGravity(GRAVITY_AMOUNT);
      lander.advance();
   
      // check for crash
      if (!ground.isAboveGround(lander.getPoint()))
      {
         lander.setAlive(false);
      }
   
      // check for just landed
      if (justLanded())
      {
         lander.setLanded(true);
      }
   }
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (lander.isAlive() && !lander.isLanded())
   {
   
      if (ui.isDown())
      {
         lander.applyThrustBottom();
      }
      
      if (ui.isLeft())
      {
         lander.applyThrustLeft();
      }
      
      if (ui.isRight())
      {
         lander.applyThrustRight();
      }
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   lander.draw();

   if (lander.isLanded())
   {
      drawText(Point(0,150), "You have successfully landed!");
   }
   
   if (!lander.isAlive())
   {
      drawText(Point(0,150), "You have crashed!");
   }
   
   if (lander.canThrust())
   {
      drawLanderFlames(lander.getPoint(), ui.isDown(), ui.isLeft(), ui.isRight());
   }
   
   Point fuelLocation;
   fuelLocation.setX(topLeft.getX() + 5);
   fuelLocation.setY(topLeft.getY() - 5);
   
   drawNumber(fuelLocation, lander.getFuel());

   // Showing the Lander's falling speed on the screen with text
   // the locations
   Point velLocationA(topLeft.getX() + 5, topLeft.getY() - 35);
   Point velLocationB(topLeft.getX() + 5, topLeft.getY() - 40);
   Point velLocationC(topLeft.getX() + 20, topLeft.getY() - 50);
   
   // drawing the text
   int fall = -lander.getVelocity().getDy();
   
   drawText(velLocationA, "Falling:");
   drawNumber(velLocationB, fall);
   drawText(velLocationC, "pixels / frame.");

   // display warning messages based on falling speed
   Point warning(topLeft.getX() + 100, topLeft.getY() - 10);

   switch (fall)
   {
      case 4:
         drawText(warning, "WARNING: Please apply thrusters!");
         break;
      case 5:
         drawText(warning, "WARNING: You are falling too fast!");
         break;
      case 6:
      case 7:
         drawText(warning, "AHHHHHHHHHHHHHHH!!!!!!!!");
         break;
      case 8:
      case 9:
         drawText(warning, "Goodbye...");
         break;
      default:
         break;
   }

   // set the lander on fire if it is falling too fast
   //    or has crashed.
   if (fall > 4 || !lander.isAlive())
      drawTopFlames(lander.getPoint());
   
   // draw ground
   ground.draw();
}

