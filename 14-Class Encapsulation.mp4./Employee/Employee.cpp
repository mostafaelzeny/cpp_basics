#include "Employee.h"
#include <iostream>

Employee::Employee()
{
    std::cout <<"Employee created\n";
}

Employee::Employee(int id, int salary, std::string name)
{
    this->id_ = id;  //this is a pointer points to the attribute of the class.similar to self in python.
    this->salary_ = salary;
    this->name_ = name;


}

int Employee::getsalary() const
{
    return salary_;
} 
void Employee::setsalary(int salary) 
{
    this->salary_ = salary;
}

