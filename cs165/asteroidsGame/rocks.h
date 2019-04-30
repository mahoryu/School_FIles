#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"
#include <cmath>

// Define the following classes here:
//   Rock
class Rock : public FlyingObject
{
  private:
   int angle;
  public:
   Rock();
   int getAngle() { return angle; }
   void setAngle(int angle) { this->angle = angle; }
   virtual int hit();
};

//   BigRock
class BigRock : public Rock
{
  public:
   BigRock();
   virtual int hit();
   virtual void draw();
};

//   MediumRock
class MediumRock : public Rock
{
  public:
   MediumRock();
   MediumRock(Velocity velocity, Point point);
   virtual int hit();
   virtual void draw();
};

//   SmallRock
class SmallRock : public Rock
{
  public:
   SmallRock();
   SmallRock(Velocity velocity, Point point);
   virtual int hit();
   virtual void draw();
};

#endif /* rocks_h */
