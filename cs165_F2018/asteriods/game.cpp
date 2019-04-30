/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
      : topLeft(tl), bottomRight(br)
{
   // Set up the initial conditions of the game
   score = 0;

   for (int i = 0; i < 5; i++)
      bRocks.push_back(BigRock());

}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   bRocks.clear();
   mRocks.clear();
   sRocks.clear();
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceRock();
   advanceShip();

   handleCollisionsBullet();
   handleCollisionsShip();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (!ship.isAlive())
         //if the ship dies kill all bullets
         bullets[i].kill();
      
      
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();

         if (!isOnScreen(bullets[i].getPoint()))
         {
            // the bullet wraps around the screen
            bullets[i].wrap();
         }

      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE ROCKS
 *
 * 1. If there are rocks, and it's alive, advance it
 * 2. Check if the rocks has gone of the screen, and if so, "wrap" it
 **************************************************************************/
void Game :: advanceRock()
{
   list <BigRock> :: iterator rockB;
   for (rockB = bRocks.begin(); rockB != bRocks.end(); ++rockB)
   {
      // we have a rock, make sure it's alive
      if (rockB->isAlive())
      {
         // move it forward
         rockB->advance();

         // check if the rock has gone off the screen
         if (!isOnScreen(rockB->getPoint()))
         {
            // The Rock wraps around the screen
            rockB->wrap();
         }
      }
   }

   list <MediumRock> :: iterator rockM;
   for (rockM = mRocks.begin(); rockM != mRocks.end(); ++rockM)
   {
      // we have a rock, make sure it's alive
      if (rockM->isAlive())
      {
         // move it forward
         rockM->advance();

         // check if the rock has gone off the screen
         if (!isOnScreen(rockM->getPoint()))
         {
            // The Rock wraps around the screen
            rockM->wrap();
         }
      }
   }

   list <SmallRock> :: iterator rockS;
   for (rockS = sRocks.begin(); rockS != sRocks.end(); ++rockS)
   {
      // we have a rock, make sure it's alive
      if (rockS->isAlive())
      {
         // move it forward
         rockS->advance();

         // check if the rock has gone off the screen
         if (!isOnScreen(rockS->getPoint()))
         {
            // The Rock wraps around the screen
            rockS->wrap();
         }
      }
   }
}

/**************************************************************************
 * GAME :: CREATE BIG ROCK
 * Create a big rock according to the rules of the game.
 **************************************************************************/
BigRock* Game :: createBigRock()
{
   BigRock* newRock = NULL;

   newRock = new BigRock();

   return newRock;
}

/**************************************************************************
 * GAME :: CREATE MEDIUM ROCK
 * Create a medium rock according to the rules of the game.
 **************************************************************************/
MediumRock Game :: createMediumRock(const Velocity & velocity, const Point & point,
                                    const int & add, const char & direction)
{
   Velocity v(velocity.getDx(), velocity.getDy());

   switch (direction)
   {
      case 'U':
         v.setDy(v.getDy() + add);
         break;
      case 'D':
         v.setDy(v.getDy() - add);
         break;
      case 'R':
         v.setDx(v.getDx() + add);
         break;
      case 'L':
         v.setDx(v.getDx() - add);
         break;
   }
   MediumRock newRock(v, point);
   return newRock;
}

/**************************************************************************
 * GAME :: CREATE SMALL ROCK
 * Create a small rock according to the rules of the game.
 **************************************************************************/
SmallRock Game :: createSmallRock(const Velocity & velocity,  const Point & point,
                                  const int & add, const char & direction)
{
   Velocity v(velocity.getDx(), velocity.getDy());

   switch (direction)
   {
      case 'U':
         v.setDy(v.getDy() + add);
         break;
      case 'D':
         v.setDy(v.getDy() - add);
         break;
      case 'R':
         v.setDx(v.getDx() + add);
         break;
      case 'L':
         v.setDx(v.getDx() - add);
         break;
   }
   SmallRock newRock(v, point);
   return newRock;
}

/***************************************
 * GAME :: ADVANCE SHIP
 * Advance the ship.
 ***************************************/
void Game :: advanceShip()
{
   // Move ship forward if it is alive
   if (ship.isAlive())
   {
      // the ship is alive, so tell it to move forward
      ship.advance();

      if (!isOnScreen(ship.getPoint()))
      {
         // the ship wraps around the screen
         ship.wrap();
      }

   }

}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
           && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
           && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
           && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS BULLET
 * Check for a collision between a rock and a bullet.
 **************************************************************************/
void Game :: handleCollisionsBullet()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, see if its too close

         list <BigRock> :: iterator rockB;
         // go through each rock
         for (rockB = bRocks.begin(); rockB != bRocks.end(); ++rockB)
         {
            // check if the rock is at this point (in case it was hit)
            if (rockB->isAlive())
            {
               // Check for collision with the bRocks and bullets
               if (getClosestDistance(bullets[i], *rockB) < rockB->getRadius())
               {
                  // create new rocks
                  mRocks.push_back(createMediumRock(rockB->getVelocity(),
                                                    rockB->getPoint(), 1, 'U'));
                  mRocks.push_back(createMediumRock(rockB->getVelocity(),
                                                    rockB->getPoint(), 1, 'D'));
                  sRocks.push_back(createSmallRock(rockB->getVelocity(),
                                                   rockB->getPoint(), 2, 'R'));
                  // hit the rock
                  score += rockB->hit();

                  // the bullet is dead as well
                  bullets[i].kill();
               } //kill rock and bullet
            }
         } // for each rock

         list <MediumRock> :: iterator rockM;
         // go through each rock
         for (rockM = mRocks.begin(); rockM != mRocks.end(); ++rockM)
         {
            // check if the rock is at this point (in case it was hit)
            if (rockM->isAlive())
            {
               // Check for collision with the bRocks and bullets
               if (getClosestDistance(bullets[i], *rockM) < rockM->getRadius())
               {
                  // create new rocks
                  sRocks.push_back(createSmallRock(rockM->getVelocity(),
                                                   rockM->getPoint(), 3, 'R'));
                  sRocks.push_back(createSmallRock(rockM->getVelocity(),
                                                   rockM->getPoint(), 3, 'L'));
                  // hit the rock
                  score += rockM->hit();

                  // the bullet is dead as well
                  bullets[i].kill();
               } //kill rock and bullet
            }
         } // for each rock

         list <SmallRock> :: iterator rockS;
         // go through each rock
         for (rockS = sRocks.begin(); rockS != sRocks.end(); ++rockS)
         {
            // check if the rock is at this point (in case it was hit)
            if (rockS->isAlive())
            {
               // Check for collision with the bRocks and bullets
               if (getClosestDistance(bullets[i], *rockS) < rockS->getRadius())
               {
                  //we have a hit!
                  // hit the rock
                  score += rockS->hit();
                  if (rockS->getSpecial())
                     ship.addShieldHP();
                  
                  // the bullet is dead as well
                  bullets[i].kill();
               } //kill rock and bullet
            }
         } // for each rock

      } // if bullet is alive

   } // for bullets
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS SHIP
 * Check for a collision between a rock and a ship.
 **************************************************************************/
void Game :: handleCollisionsShip()
{
   list <BigRock> :: iterator rockB;
   // go through each rock
   for (rockB = bRocks.begin(); rockB != bRocks.end(); ++rockB)
   {
      // check if the rock is at this point (in case it was hit)
      if (rockB->isAlive() &&
          getClosestDistance(ship, *rockB) < max(rockB->getRadius(),
                                                 ship.getRadius()))
      {
         // hit ship and the rock
         ship.hit();
         ship.bounce();
         score -= rockB->hit();

         // create new rocks
         mRocks.push_back(createMediumRock(rockB->getVelocity(),
                                           rockB->getPoint(), 1, 'U'));
         mRocks.push_back(createMediumRock(rockB->getVelocity(),
                                           rockB->getPoint(), 1, 'D'));
         sRocks.push_back(createSmallRock(rockB->getVelocity(),
                                          rockB->getPoint(), 2, 'R'));
      } 

   }

   list <MediumRock> :: iterator rockM;
   // go through each rock
   for (rockM = mRocks.begin(); rockM != mRocks.end(); ++rockM)
   {
      // check if the rock is at this point (in case it was hit)
      if (rockM->isAlive() &&
          getClosestDistance(ship, *rockM) < max(rockM->getRadius(),
                                                 ship.getRadius()))
      {
         // hit ship and the rock
         ship.hit();
         ship.bounce();
         score -= rockM->hit();

         // create new rocks
                  sRocks.push_back(createSmallRock(rockM->getVelocity(),
                                                   rockM->getPoint(), 3, 'R'));
                  sRocks.push_back(createSmallRock(rockM->getVelocity(),
                                                   rockM->getPoint(), 3, 'L'));
      } 

   }

   list <SmallRock> :: iterator rockS;
   // go through each rock
   for (rockS = sRocks.begin(); rockS != sRocks.end(); ++rockS)
   {
      // check if the rock is at this point (in case it was hit)
      if (rockS->isAlive() &&
          getClosestDistance(ship, *rockS) < max(rockS->getRadius(),
                                                 ship.getRadius()))
      {
         ship.hit();
         ship.bounce();
         score -= (rockS->hit()+ 50);
      } // hit ship and the rock

   }
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate rock)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;

      if (!bullet.isAlive())
      {
         // If we had a list of pointers, we would need to delete the memory here...


         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }

}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the ship
   if (ui.isLeft())
   {
      ship.rotateL();
   }

   if (ui.isRight())
   {
      ship.rotateR();
   }

   if (ui.isUp())
   {
      ship.thrust();
      ship.setThrusters(true);
   }
   if (!ui.isUp())
   {
      ship.setThrusters(false);
   }

   // Check for "Spacebar
   if (ui.isSpace() && ship.isAlive())
   {
      Bullet newBullet;
      newBullet.fire(ship.getPoint(), ship.getAngle(), ship.getVelocity());

      bullets.push_back(newBullet);
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // draw the rocks
   list <BigRock> :: iterator rockB;
   for (rockB = bRocks.begin(); rockB != bRocks.end(); ++rockB)
   {
      if (rockB->isAlive())
         rockB->draw();
   }
   list <MediumRock> :: iterator rockM;
   for (rockM = mRocks.begin(); rockM != mRocks.end(); ++rockM)
   {
      if (rockM->isAlive())
         rockM->draw();
   }
   list <SmallRock> :: iterator rockS;
   for (rockS = sRocks.begin(); rockS != sRocks.end(); ++rockS)
   {
      if (rockS->isAlive())
         rockS->draw();
   }

   // draw the ship
   if (ship.isAlive())
      ship.draw();
   else
   {
      drawText(Point(-55,0), "GAME OVER");
   }

   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }

   // Put the score on the screen
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);

   drawNumber(scoreLocation, score);

}
