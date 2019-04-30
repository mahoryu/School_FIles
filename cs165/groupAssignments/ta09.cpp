#include <iostream>
#include <string>

using namespace std;


class Employee
{
private:
   string name;
public:
   Employee() { setName("Unknown"); }
   Employee(string name)
   { setName(name); }
   string getName() { return name; }
   void setName(string name) { this->name = name; }
   virtual void display() { cout << name; }
};


class HourlyEmployee : public Employee
{
private:
   int hourlyWage;
public:

   int getHourlyWage() { return hourlyWage; }
   void setHourlyWage(int hourlyWage) { this->hourlyWage = hourlyWage; }
   virtual void display()
   {
      cout << getName() << " - $" << hourlyWage << "/hour";
   }
};


class SaleryEmployee : public Employee
{
private:
   int salery;
public:
   SaleryEmployee(string name, int salery)
   {
      setName(name);
      setSalery(salery);
   }
   int getSalery() { return salery; }
   void setSalery(int salery) { this->salery = salery; }
   virtual void display()
   {
      cout << getName() << " - $" << salery << "/year";
   }
};

#define SIZE 3

int main()
{   
   Employee* employees[SIZE];
   char input;

   for (int i = 0; i < SIZE; i++)
   {
      cout << "Press 'h' for hourly and 's' for salery: ";
      cin  >> input;
      

      string name;
      cout << "Name : ";
      cin  >> name;
      
      if (input == 'h')
      {
         int hourlyRate;
         cout << "Hourly Rate: ";
         cin  >> hourlyRate;

         HourlyEmployee* hourlyEmployee = new HourlyEmployee;
         hourlyEmployee->setName(name);
         hourlyEmployee->setHourlyWage(hourlyRate);
         employees[i] = hourlyEmployee;
      }
      else
      {
         int salery;
         cout << "Salery: ";
         cin  >> salery;

         employees[i] = new SaleryEmployee(name, salery);
      }
   }

   for (int i = 0; i < SIZE; i++)
   {
      employees[i]->display();
      cout << endl;
   }

   for (int i = 0; i < SIZE; i++)
   {
      delete employees[i];
      employees[i] = NULL;
   }
      
   return 0;
}
