#include <iostream>

class B
{
    public:
    B()= default;
    void fun()
    {
        std::cout<<"Normal Aggregation (by refrence)"<<std::endl;
    }

};

class A
{
    public:
    A(B &b1):b(b1)
    {
      b.fun();
    }

    private:
    B &b;

};
int main()
{
    B b; 
    A a(b);
    return 0;
}