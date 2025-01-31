#include "velocity.h"

#include <iostream>
using namespace std;

// TODO: Put your method bodies here


Velocity :: Velocity (float dx, float dy)
{
   this->dx = dx;
   this->dy = dy;
}


void Velocity :: prompt()
{
   cout << "dx: ";
   cin >> dx;

   cout << "dy: ";
   cin >> dy;
}

void Velocity :: display() const 
{
   cout << "(dx=" << dx << ", dy=" << dy << ")";
}

// +
Velocity operator + (const Velocity & lhs, const Velocity & rhs)
{
   return Velocity(lhs.getDx() + rhs.getDx(), lhs.getDy() + rhs.getDy());
}
// +=
Velocity & operator += (Velocity & lhs, const Velocity & rhs)
{
   lhs = lhs + rhs;
   return lhs;
}
