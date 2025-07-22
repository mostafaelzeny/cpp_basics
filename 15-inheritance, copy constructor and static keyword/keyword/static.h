#ifndef STATIC_H
#define STATIC_H

class my_class
{
    
    public:
    my_class();
    
    static void my_function(); // static member function Can Be Called Without Creating an Object and Can Access Static Variables only.
    // static member function has no this pointer.
    private:
    static int instance;
    
};


#endif