#include <iostream>

class B
{
    public:
    B()= default;
    void fun()
    {
        std::cout<<"Normal Composition"<<std::endl;
    }

};

class A
{
    public:
    A()
    {
      b.fun();
    }

    private:
    B b;

};
int main()
{

    A a;
    return 0;
}