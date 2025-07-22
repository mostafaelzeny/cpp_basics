#include <iostream>
template<typename T>

class Smartptr
{
    public:

    Smartptr()
    {
        ptr = new T{0};
    }
    Smartptr(T *ptr_)
    {
        ptr = ptr_;

    }

    // Smartptr(const Smartptr& copy)
    // {
    //     this->ptr = copy.ptr;

    // }

    T& operator*()
    {
        return *ptr;
    }

    ~Smartptr()
    {
        
        delete ptr;
        std::cout<<"ptr deleted"<<std::endl;
    }

    private:
    T *ptr;


};



int main()
{
    Smartptr<int> sptr(new int{15});
    *sptr = 300;

    // Smartptr copyptr(sptr);

    std::cout<<"value in ptr = "<<*sptr<<std::endl;
    // std::cout<<"value in ptr = "<<*copyptr<<std::endl;

    


    return 0;

}