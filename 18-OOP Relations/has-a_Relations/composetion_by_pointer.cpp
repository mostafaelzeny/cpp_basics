#include <iostream>

class B
{
    public:
    B()= default;
    void fun()
    {
        std::cout<<"Making composition by pointer"<<std::endl;
    }

};

class A
{
    public:
    A()
    {
        b = new B();
        b->fun();
    }


    ~A()
    {
        delete b;
    }

    private:
    B *b;

};
int main()
{

    A a;
    return 0;
}