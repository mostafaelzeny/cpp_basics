#include <iostream>
#include <memory>
class B;
class A
{
    public:
    A()
    {

    }

   ~A()
   {
    std::cout<<"Destructor for A"<<std::endl;
   } 


    
    std::shared_ptr<B> ptrb;
};

class B
{
    public:
    B(){}
     ~B()
   {
    std::cout<<"Destructor for B"<<std::endl;
   } 


    
    std::weak_ptr<A>ptra;//if i didn't use weakptr hear the deconstructor will not occur and will lead to memory leak.
};

int main()
{
    std::shared_ptr<A> ptrA = std::make_shared<A>();
    std::shared_ptr<B> ptrB = std::make_shared<B>();

    ptrA->ptrb = ptrB;
    ptrB->ptra = ptrA;
    return 0;
}