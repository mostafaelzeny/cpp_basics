//Virtual methods enable runtime polymorphism,
//allowing a derived class to override a base class function and ensure the correct function is called,
//even when accessed through a base class pointer.
#include <iostream>
#include <vector>

class Shape 
{
    public:
    virtual double area()
    {
        return 5*4;
    }
    double perimeter();
    //virtual void show()=0;//force implementation for this function in any child calss.

    virtual ~Shape()
    {
        std::cout<<"shape destructor"<<std::endl;
    }

};

class Circle:public Shape
{
    public:
    Circle(double r): radius(r)
    {}
    double area()  override //override give me an error if i wrote area wrong. 
    {
        return 3.14 * radius * radius;

    }

    double perimeter()
    {
        return 3.14 * 2 *radius;
    }



    double radius;

     ~Circle()
    {
        std::cout<<"Circle destructor"<<std::endl;
    }
};

class Square:public Shape
{
    public:
    Square(double s): side(s)
    {}
    double area() 
    {
        return  side * side;

    }

    double perimeter()
    {
        return  2 *side;
    }



    double side;
};


int main()
{

    std::vector<Shape *>vec;
    vec.push_back(new Circle(5));
    vec.push_back(new Square(5));
    Circle c1(5);
    //Square s1(5);


    Shape * my_shape = &c1;
    //Shape * my_shapee = &s1; 
 
    //std::cout<<c1.area()<<std::endl;
   // std::cout<<my_shape->area()<<std::endl;//if there is no virtual it will print area inside paerent class.
    // std::cout<<my_shape->area()<<std::endl;

    // for(Shape * shapee:vec)
    // {
    //     std::cout<<shapee->area()<<std::endl;

    // }

    for(auto &shapee : vec)
    {
         std::cout<<shapee->area()<<std::endl;

    }


    return 0; 
}