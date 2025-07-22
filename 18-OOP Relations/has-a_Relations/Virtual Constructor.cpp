//benefit of using virtual destructor is when you delete the pointer to you child class will call both destructor parent desctructor and child destructor.
//In this cad I override the parent destructor. 

#include <iostream>
#include <vector>


class Animal
{
    public:
    Animal(){

    }
    virtual void Makesound()=0;
    virtual ~Animal()
    {
        std::cout<<"Animal destructor"<<std::endl;
    };

    private:



};

class Cat:public Animal
{
    public:
    Cat()
    {
        
        std::cout<<"In cat constructor"<<std::endl;


    };
    void Makesound()override
    {
        std::cout<<"cat sound"<<std::endl;
    }
    ~Cat()
    {

    };



    private:

};
class Dog:public Animal
{
    public:
    void Makesound()override
    {
        std::cout<<"dog sound"<<std::endl;
    }
    void Dogfun()
    {

        std::cout<<"Add function to derived class Dog"<<std::endl;
    }
    ~Dog()
    {
    };



    private:

};
void printsound(std::vector<Animal *>&animals)
{
    for(auto &animal: animals)
    {
        animal->Makesound();
        if(Dog *dog = dynamic_cast<Dog*>(animal))
        { 
            dog->Dogfun();

        }
        else 
        {
            std::cout<<"functin not found"<<std::endl;
        }
        
    }

}

int main()
{
    std::vector<Animal*>animals;

    Cat cat1, cat2, cat3;
   Dog dog1,dog2, dog3;

    animals.push_back(&cat1);
    animals.push_back(&cat2);
    animals.push_back(&cat3);

    animals.push_back(&dog1);
    animals.push_back(&dog2);
    animals.push_back(&dog3);


      printsound(animals);




    // Animal* base;
    // base = new Cat;
    // base = new Dog;
    // ((Dog*)base)->Dogfun();// valid syntax.
    

    // delete base;


    return 0;
}