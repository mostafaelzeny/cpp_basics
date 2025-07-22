#include <iostream>
#include"Book.h"

void Book::Display()
{
    std::cout<<"We are in display and the Author are :"<<Author<<std::endl;

}

void Book::set_price(double new_price)
{
    this->Price = new_price;

}

double Book::get_price()
{
    return this->Price;
}