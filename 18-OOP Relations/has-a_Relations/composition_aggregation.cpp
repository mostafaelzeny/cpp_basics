#include <iostream>


class Memory
{
    public:
    Memory()
    {
        std::cout<<"Default constructor for memory"<<std::endl;
    }

    void fun()
    {
        std::cout<<"inside fun"<<std::endl;
    }
    ~Memory()
    {
        std::cout<<"Destructor for memory"<<std::endl;
    }
};

class computer
{
    public:
    computer()
    {
       mem = new Memory();// Composition: computer "has an" Memoryt and controls its lifecycle. Making the object inside the class constructor.
       mem->fun();

        std::cout<<"Default constructor for computer"<<std::endl;
    }

    computer(Memory * new_mem):mem(new_mem)
    {
        new_mem->fun();

    }

   ~computer()
   {
    std::cout<<"Decstructor for computer"<<std::endl;

    delete mem;

   }

    private:
    Memory *mem;  
};

int main()
{

    computer c1;

    Memory mem1;  //aggregation, Making the object out side the class .
    computer c2(&mem1); 
    

    return 0;
}