#include <iostream>
 
template<typename T>
class smartptr
{
    public:

    smartptr(){}
    smartptr(T *p = nullptr): ptr(p)
    {
       
    }

    T &operator*()
    {
        return *ptr;
    }


    smartptr(smartptr & copy) = delete;

    smartptr &operator=(smartptr &other) = delete;

    smartptr (smartptr && other) noexcept  //move constructor in smarptr shoul take rvalue reference.
    {
        this->ptr = other.ptr;
        other.ptr = nullptr;

    }


    ~smartptr()
    {
        delete ptr;
    }



    private:
    T* ptr;


};

int main()
{
    smartptr<int> sp(new int(10));
    std::cout<<*sp<<std::endl;

    
    smartptr<int> Smart2 = std::move(sp); // Move ownership
    
        std::cout << *Smart2 << std::endl; 
      

    return 0;

}