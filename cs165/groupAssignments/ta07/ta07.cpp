#include <iostream>
using namespace std;

// Core requirements
float getValueFromPointer(float* propeller);
float* getMinValue(float* a, float* b);

// Stretch goals
void swapElements(float* theArray[], int a, int b);
void sortArray(float* theArray[]);

int main()
{  
   
   int arraySize;
   cout << "Enter the array size: ";
   cin >> arraySize;

   // Allocate your array(s) here
   float * propeller = new float[arraySize];
      
   // Fill your array with float values
   for(int i = 0; i < arraySize; i++) 
   {
          cout << "Enter a float value: ";
          cin >> propeller[i];
   }

   
   for (int i = 0; i < arraySize; i++)
   {
      float *p = &propeller[i];
      float value = getValueFromPointer(p);
      cout << "The value of the element " << i << " is: ";
      cout << value << endl;
   }
   

   
   // Print the smaller of the first and last elements of the array
   float *p = &propeller[0];
   float *pointerToMin = getMinValue(p, p + (arraySize-1));
   cout << *pointerToMin << endl;
   

   // Clean up your array(s) here
   delete[] propeller;
   return 0;
}

float getValueFromPointer(float* propeller)
{
   float speed = *propeller;
   propeller++;
   return speed;
}

float* getMinValue(float* a, float* b)
{
   if (*a < *b)
      return a;
   else
      return b;
}
