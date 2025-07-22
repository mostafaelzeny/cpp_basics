#include "Book.h"
#include<iostream>


int main()
{
    
    Book book1("yousef","OOP",100); 
    book1.Display();
    std::cout<<book1.get_price()<<std::endl;
    book1.set_price(200);
    std::cout<<book1.get_price()<<std::endl;


    Book book2;
    book2.Display();

    Book copy_cons = book1;
   // book1.Display();

    

    
    
    
    
    
    return 0;


} 