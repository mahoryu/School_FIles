/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "bullet.h"
#include "ship.h"
#include "rocks.h"

#define CLOSE_ENOUGH 15

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
  public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br);
   ~Game();

   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);

   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();

   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);

  private:
   Point topLeft;
   Point bottomRight;

   int score;

   Ship ship;
   vector<Bullet> bullets;

   list<BigRock> bRocks;
   list<MediumRock> mRocks;
   list<SmallRock> sRocks;
   

   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2);
   bool isOnScreen(const Point & point);
   void advanceBullets();
   void advanceRock();
   BigRock* createBigRock();
   MediumRock createMediumRock(const Velocity & velocity, const Point & point,
                                const int & add, const char & direction);
   SmallRock createSmallRock(const Velocity & velocity, const Point & point,
                              const int & add, const char & direction);
   void advanceShip();

   void handleCollisionsBullet();
   void handleCollisionsShip();
   void cleanUpZombies();
   
};

#endif /* GAME_H */
