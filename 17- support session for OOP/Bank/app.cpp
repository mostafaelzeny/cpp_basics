#include <iostream>

class Rectangle
{
    public:
    Rectangle(int length, int width)
    {
        this->length_ = length;
        this->width_ = width;

    }

    void setLength(int length)
    {
        this->length_ = length;
    }
    int getLength()
    {
        return length_;
    }
   void setWidth(int width)
    {
        this->width_ = width;
    }
    int getWidth()
    {
        return width_;
    }

    int area()
    {

        return length_*width_;
    }

    protected:

    int length_;
    int width_;


};

class Square: public Rectangle
{
    public:
    Square(int side):Rectangle(side,side)
    {

    }
    
    protected:
    int side;




};

void display(Rectangle &rec)
{
    auto actual_length = rec.getLength()
    auto actua_area = actual_length*rec.get
}




int main()
{

    Rectangle rec(5,5);
    Square square(5);

    std::cout<<rec.area()<<std::endl;
    std::cout<<square.area()<<std::endl;










    return 0;

}