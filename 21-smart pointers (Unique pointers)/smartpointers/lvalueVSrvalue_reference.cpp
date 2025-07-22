#include <iostream>
using namespace std;



int GetValue(){
    return 10;
}

int& GetValueRef()
{
    static int value = 10; // Data segment
    
    return value;
}

void printName(string &name) //&
{
    cout <<"Left Value Reference " << name << endl;
}

void printName(string&& name) //rvalue reference
{
    cout <<"Right Value Reference " << name<< endl; 
}


int main()
{
   

    string firstName = "Robotics"; //temp
    string lastName = "Corner"; //temp

    string fullName = firstName + lastName ;
 
    printName(fullName);
   
    printName(firstName + lastName); // works with rvalue Reference because Expressions like firstName + lastName return a temporary string (rvalue).

    return 0;
}