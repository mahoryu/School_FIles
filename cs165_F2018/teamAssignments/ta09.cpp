#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
   string name;
public:
   string getName()          {return name;}
   void setName(string name) {this->name = name;}
   virtual void display()    {cout << name << endl;}
};

class HourlyEmployee : public Employee
{
private:
   int hourlyWage;
public:
   HourlyEmployee(string name, int hourlyWage)
   {
      setName(name);
      setWage(hourlyWage);
   }
   int getWage()          {return hourlyWage;}
   void setWage(int hourlyWage) {this->hourlyWage = hourlyWage;}
   virtual void display()
   {
      cout << getName() << " - $" << hourlyWage << "/hour\n";
   }
};

class SalaryEmployee : public Employee
{
private:
   int salary;
public:
   SalaryEmployee() {}
   SalaryEmployee(string name, int salary)
   {
      setName(name);
      setSalary(salary);
   }
   int getSalary()            {return salary;}
   void setSalary(int salary) {this->salary = salary;}
   virtual void display()
   {
      cout << getName() << " - $" << salary << "/year\n";
   }
};

int main()
{
   Employee * employees[3];

   for (int i = 0; i < 3; i++)
   {
      char type;
      do
      {
         cout << "Please enter an employee (h/s): ";
         cin  >> type;
      }
      while (type != 'h' && type != 's');

      string name;
      cout << "Please enter Employee name: ";
      cin  >> name;      

      if (type == 'h')
      {
         int wage;
         cout << "Please enter hourly wage: ";
         cin  >> wage;
         employees[i] = new HourlyEmployee(name, wage);
      }
      else 
      {
         int salary;
         cout << "Enter the salary: ";
         cin >> salary;

         // It would be best to check for valid integers here...

         SalaryEmployee* salaryEmployee = new SalaryEmployee;
         salaryEmployee->setName(name);
         salaryEmployee->setSalary(salary);

         employees[i] = salaryEmployee;
         /*
         int salary;
         cout << "Please enter yearly salary: ";
         cin  >> salary;
         employees[i] = new SalaryEmployee(name, salary);
         */
      }
   }

   for (int i = 0; i < 3; i++)
   {
      employees[i]->display();
   }
   
   for (int i = 0; i < 3; i++)
   {
      delete employees[i];
      employees[i] = NULL;
   }
   
   return 0;
}
