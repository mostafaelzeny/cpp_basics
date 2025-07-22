#include <iostream>
#include <cstring>

class String
{
    char * data;
    size_t length ;


    public:
    String(): data(nullptr), length(0){}

    String(const char *d)
    {
        length = strlen(d);
        data = new char[length +1];
        strcpy(data,d);
        std::cout << "Constructed: " << data << std::endl; 

    }
    // Copy Constructor (Deleted to prevent copying)
    String(const String& other) = delete;

    // Copy Assignment (Deleted to prevent copying)
    String& operator=(const String& other) = delete;

    String (String &&other) noexcept
    {
        this->data = other.data;
        other.data = nullptr;
        other.length = 0;
        std::cout << "Moved (Constructor): " << data << std::endl;

    }
    
    ~String() {
        if (data) {
            std::cout << "Destroyed: " << data << std::endl;
            delete[] data;
        }
    }
    void print()  {
        if (data) std::cout << "String: " << data << std::endl;
        else std::cout << "String is empty" << std::endl;
    }

};

class Entity
{
    String name;
    public:
    Entity(){}
    Entity(String &&str):name(std::move(str))
    {
        std::cout<<"moved in Entity"<<std::endl;
        
    }
    void printName()  {
        name.print();
    }

};

int main()
{
     String str1("Hello, World!");
    str1.print();
    String str2 = std::move(str1);
    str2.print();

    std::cout << "\n--- Entity Example ---\n";
    Entity e(std::move(str2));
    e.printName();



    return 0;
}