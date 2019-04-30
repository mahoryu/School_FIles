#ifndef BAG_H
#define BAG_H

/***********************************************************
 * Class: Bag
 * Description: Holds ints...for now
 ***********************************************************/
template <class T>
class Bag
{
private:
   int capacity;
   int size;
   int currentAddIndex;
   T* data;

public:
   Bag(); // Default constructor
   ~Bag();
   
   // Getters
   int getCapacity() {return capacity;}
   int getCount()    {return size;}

   T getItem(int index) {return data[index];}
   void addItem(T item); 
};
template <class T>
Bag<T> :: Bag()
{
   data = new T[5];
   capacity = 5;
   size = 0;
   currentAddIndex = 0;
}

template <class T>
Bag<T> :: ~Bag()
{
   if (data != NULL)
   {
      delete[] data;
      data = NULL;
   }
}

template <class T>
void Bag<T> :: addItem(T item)
{
   if (size == capacity)
   {
      capacity *= 2;
      T* newData = new T[capacity];
      for(int i = 0; i < currentAddIndex; i++)
         newData[i] = data[i];
            
      delete[] data;
      data = newData;
   }
   
   data[currentAddIndex] = item;
   currentAddIndex++;
   size++;
}

#endif

