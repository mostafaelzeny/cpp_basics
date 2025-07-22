#include <iostream>
#include "static.h"
int value;
static int my_max_val = 0 ;  // static global variable . This variable is stored in .bss
// You can't use static global variable in other files.
int Getmaxvalue(int a)
{
    static int max =0; //static local variable. This variable is stored in .data 

    max = (max > a)? max : a;
    return max;

}

  void my_fun() //static function can't be seen in oher files .
{
    std::cout<<"hello\n";
}


    void my_class::my_function()
    {
        std::cout<< "class static function \n"<<instance<<std::endl;
    }
    int my_class::instance = 0;
    my_class::my_class()
    {
          instance++;
    };    
    

