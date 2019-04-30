#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
private:
   float dx;
   float dy;

public:
   Velocity()
   {
      dx = 0;
      dy = 0;
   }
   Velocity(float dx, float dy);
   /**************************
    * Getters and Setters
    **************************/
   float getDx() const { return dx; }
   float getDy() const { return dy; }

   void setDx(float dx) { this->dx = dx; }
   void setDy(float dy) { this->dy = dy; }

   /**************************
    * Public member functions
    **************************/
   void prompt();
   void display() const;

   friend Velocity operator - (const Velocity & lhs, const Velocity & rhs)
   {
      return Velocity(lhs.dx - rhs.dx, lhs.dy - rhs.dy);
   }
   friend Velocity operator -= (Velocity & lhs, const Velocity & rhs)
   {
      lhs = lhs - rhs;
      return lhs;
   }
};

Velocity operator + (const Velocity & lhs, const Velocity & rhs);
Velocity operator += (Velocity & lhs, const Velocity & rhs);




#endif
