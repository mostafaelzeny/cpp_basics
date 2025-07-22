#include <iostream>
static int count = 0;


class Sharedptr
{
    public:

    Sharedptr(int value){
        count =1;
        ptr = new int{value};
    }
    Sharedptr(int *p = nullptr): ptr(p)
    {
       
    }

    int &operator*()
    {
        return *ptr;
    }


     Sharedptr(Sharedptr & copy) 
     {
        count++;
        this->ptr = copy.ptr;
        
     }

    Sharedptr &operator=(Sharedptr &copy) 
    {
        count++;
        this->ptr = copy.ptr;
        return *this;
    }

    Sharedptr (Sharedptr && other) noexcept  //move constructor in smarptr shoul take rvalue reference.
    {
        this->ptr = other.ptr;
        other.ptr = nullptr;
        

    }

    int get_count()
    {
        return count;
    }


    ~Sharedptr()
    {
        count--;
        if(count ==0)
        delete ptr;
    }



    private:
    int* ptr;


};


int main()
{
    Sharedptr sp(6);
    std::cout<<*sp<<std::endl;
    Sharedptr sp2(sp);
    std::cout<<*sp<<std::endl;
    
    Sharedptr sp3(sp);
    std::cout<<sp3.get_count()<<std::endl;

    Sharedptr spo(8);
    Sharedptr spo2(spo);
    std::cout<<spo2.get_count()<<std::endl;
    



    
    return 0;

}