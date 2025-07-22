#include <iostream>
#include <iterator>
#include <unordered_map>
using namespace std;
template <typename T1, typename T2>

class xpair
{
    public:
    xpair(T1 first_,T2 second_):first(first_), second(second_)
    {

    }

    static xpair Make_xPair(T1 local_first, T2 local_second)
	{
		return xpair(local_first, local_second);
	}



    private:
    T1 first;
    T2 second;

  
};



int main()
{
    auto p2 = xpair<int, string>::Make_xPair(20, "World");

    unordered_map<string, int> mymap;
    mymap.insert(make_pair<std::string, int>("Mo Salah", 11));
    mymap["Mo"] = 10;

    // for(auto &pair :mymap)
    // {
    //     auto key = pair.first;
    //     auto value = pair.second;
    //     cout<<key<<" "<<value<<std::endl;
    // }

    // another way to print map values.
    // for(auto &[key, value] :mymap)
    // {
        
    //     cout<<key<<" "<<value<<std::endl;
    // }
    
    // another way to print map values.
    mymap.erase("Mo");
    for(auto itr = mymap.begin(); itr != mymap.end(); itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }



    return 0;
}


