#include <iostream>
template<typename T>
T Max_function(T a, T b)
{
    return a > b? a: b;
}

// double Max_function(double a, double b)
// {
//     return a > b? a: b;
// }
int main()
{
    double x=5.3;
    double y=7.8;
    std::cout<<Max_function<double>(x, y)<<std::endl;
    std::cout<<Max_function(5, 6)<<std::endl;


    return 0;
}