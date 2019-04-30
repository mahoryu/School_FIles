#ifndef ROCKS_H
#define ROCKS_H

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"

/*********************************************
 * ROCK
 * Base class for the rock objects.
 *********************************************/
class Rock : public FlyingObject
{
  public:
   // interations
   virtual int hit();
   virtual void draw() = 0;
};

/*********************************************
 * BIG_ROCK
 * Class for the big rock objects.
 *********************************************/
class BigRock : public Rock
{
  public:
   BigRock();
   virtual void draw();
};

/*********************************************
 * MEDIUM_ROCK
 * Class for the medium rock objects.
 *********************************************/
class MediumRock : public Rock
{
  public:
   MediumRock(Velocity v, Point p);
   virtual void draw();
};

/*********************************************
 * SMALL_ROCK
 * Class for the small rock objects.
 *********************************************/
class SmallRock : public Rock
{
  private:
   bool special;
  public:
   SmallRock(Velocity v, Point p);

   bool getSpecial() {return special;}
   
   virtual int hit();
   virtual void draw();
};


#endif /* ROCKS_H */
