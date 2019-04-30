/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

// TODO: Fill in this class
// Put all of your method bodies right in this file
template <class T1, class T2>
class Pair
{
  private:
   T1 v1;
   T2 v2;
   
  public:
   T1 getFirst()            {return v1;}
   T2 getSecond()           {return v2;}

   void setFirst(T1 value)  {v1 = value;}
   void setSecond(T2 value) {v2 = value;}

   void display();
};

template <class T1, class T2>
void Pair<T1, T2> :: display()
{
   cout << getFirst() << " - " << getSecond();
}


#endif // PAIR_H
