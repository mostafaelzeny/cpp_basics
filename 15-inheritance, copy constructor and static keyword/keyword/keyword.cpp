#include "static.h"
#include <iostream>
extern int Getmaxvalue(int a);
extern void my_fun();


int main()
{
    int n1= 8, n2 = 7 , n3 = 15;
    int max = Getmaxvalue(n1);
    std::cout<<max<<std::endl;

    max = Getmaxvalue(n2);
    std::cout<<max<<std::endl;

    max = Getmaxvalue(n3);
    std::cout<<max<<std::endl;
    
    my_fun();

    my_class obj1;
    my_class obj2;
    my_class::my_function(); // No object needed in static member function .
   




    return 0;
}
