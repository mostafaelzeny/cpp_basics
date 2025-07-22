#ifndef BOOK_H
#define BOOK_H
#include <iostream>



class Book
{
    public:

    Book() :Author(""), Title("unknown"), Price(0)
    {

    }

    Book(std::string P_Author, std::string P_Title,double price ):Author(P_Author), Title(P_Title), Price(price)
    {

    }

    Book(const Book& copied_Book)
    {
        std::cout<<"copy constructor used"<<std::endl;
        this->Author = copied_Book.Author;
        this->Title = copied_Book.Title;
        this->Price = copied_Book.Price;

    }


    void Display();

    void set_price(double new_price); 

    double get_price();


    private:

    std::string Title;
    std::string Author;
    double Price;

};










#endif