#include <iostream>

class B
{
    public:
    B()= default;
    void fun()
    {
        std::cout<<"Making Aggregation by pointer"<<std::endl;
    }

};

class A
{
    public:
    A(B *b1):b(b1)
    {
        
        b->fun();
    }


    private:
    B *b;

};
int main()
{
    B *b = new B();
    A a(b);
    delete b;
    return 0;
}