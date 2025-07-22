#include <iostream>
#include <set>
#include <unordered_set>

int main()
{
    std::set<int> myset = {6, 8, 2, 9, 9};
    myset.insert(10); 
    for(auto &num:myset)
    {
        std::cout<<num<<" "<<std::endl;
    }

    std::cout<<std::endl;

    std::multiset<int> mymultiset = {6, 8, 2, 9, 9};
    mymultiset.insert(10); 
    for(auto &num:mymultiset)
    {
        std::cout<<num<<" "<<std::endl;
    }

    std::cout<<std::endl;

    std::unordered_set<int> myunorderedset = {6, 8, 2, 9, 9};
    myunorderedset.insert(10);
    myunorderedset.erase(6); 
 

    for(auto &num:myunorderedset)
    {
        std::cout<<num<<" "<<std::endl;
    }


}
