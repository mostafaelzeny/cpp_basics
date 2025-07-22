#include <iostream>



class Sharedptr
{
    public:

    Sharedptr(int value){
        count = new int{1};
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
        
        this->ptr = copy.ptr;
        this->count = copy.count;
        (*count)++;

        
     }

    Sharedptr &operator=(Sharedptr &copy) 
    {
        this->ptr = copy.ptr;
        this->count = copy.count;
        (*count)++;
        return *this;
    }

    Sharedptr (Sharedptr && other) noexcept  //move constructor in smarptr shoul take rvalue reference.
    {
        this->ptr = other.ptr;
        other.ptr = nullptr;
        

    }

    int get_count()
    {
        return (*count);
    }


    ~Sharedptr()
    {
        (*count)--;
        if(*count ==0)
        delete ptr;
    }



    private:
    int* ptr;
    int *count ;


};


int main()
{
    Sharedptr sp(6);
   
    Sharedptr sp2(sp);
 
    
    Sharedptr sp3(sp);
    

    Sharedptr spo(8);
    Sharedptr spo2(spo);
    std::cout<<sp3.get_count()<<" " << spo.get_count()<<std::endl;

    
    return 0;

}