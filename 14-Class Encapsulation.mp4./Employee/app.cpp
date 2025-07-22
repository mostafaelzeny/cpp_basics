#include "Employee.h"

#include <iostream> 
void my_function(const Employee& object)
{
    std::cout << object.getsalary()<< std::endl;

}

int main()
{
    Employee emp1;
    Employee Employee1(1,100,"Mo");
    std::cout << Employee1.getsalary()<< std::endl;
    my_function(Employee1);

    //Employee * emp_ptr = nullptr;
    //emp_ptr = &Employee1;
    //std::cout << emp_ptr->getsalary()<< std::endl;//pointer to Object.

    return 0;
}