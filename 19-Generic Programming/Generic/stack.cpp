#include <iostream>
#include <vector>
class Stack
{
    public:
    Stack()
    {
        std::cout<<"Stack is initialized."<<std::endl;
    }
    Stack(int size_):size(size_)
    {

    }

    void push(int x)
    {
        if(!isFull())
        {
            stack.push_back(x);
            top++;
        }
    }

    void pop()
    {
        if(!isEmpty())
        {
            stack.erase(stack.begin() + top);
            top--; 
        } 
        else
        {
            std::cout<<"Stack is empty"<<std::endl;
        }     
    }

    bool isFull()
    {
      return top==size-1;
    }
    bool isEmpty()
    {
      return top==-1;
    }

    void display()
    {
        for(auto item:stack)
        {
            std::cout<<item<<std::endl;
        }

    }

    private:
    std::vector<int> stack;
    int top=-1;
    int size ;


};

int main()
{

    Stack stack1(5);
    stack1.push(5);
    stack1.push(3);
   
    stack1.pop();
    stack1.pop();
    stack1.pop();


    






    stack1.display();

   
    return 0;
}