//function / operator + overloading.
#include <iostream>
class complex
{
    public:
    complex(double real =0, double img =0):real_(real), img_(img)
    {


    }
    

    complex operator+(const complex &other)
    {
        complex result;  // ✅ Create a temporary object
        result.real_ = this->real_ + other.real_;
        result.img_ = this->img_ + other.img_;
        return result;  // ✅ Return the result object

        
    }

friend std::ostream& operator<<(std::ostream& os, const complex &c)
{
    os << c.real_ << '+' << c.img_ << 'i';
    return os; 
}


    private:
    double real_;
    double img_;
};



int main()
{
    complex num1(2,5);
    complex num2(3,4);
    complex num3(0,0);
     num3 = num1 + num2;
   // std::cout<<num3.real_<<std::endl;
    //std::cout<<num3.img_<<std::endl;
    std::cout<< num3<<std::endl;
    return 0;
}