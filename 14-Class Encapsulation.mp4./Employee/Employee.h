#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>

class Employee
{
    public:
    Employee();
    Employee(int id, int salary, std::string name);

    void setsalary(int salary) ; 
    int getsalary() const;
    
    private:
    int id_;
    int salary_;
    std::string name_;
};
 

 #endif