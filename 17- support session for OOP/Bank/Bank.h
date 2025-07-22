#ifndef BANK_H
#define BANK_H
#include <iostream>
class Bank
{
    public:
    virtual void ProcessPayment() = 0;// Pure virtual functin deosn't allow me to make object from parent class.
    Bank()
    {

    };

    Bank(std::string name,double amount)
    {
        this->amount_= amount;
        this->name_ = name;

    };

    void setAmount(double amount)
    {
        this->amount_= amount;
    }
    double getAmoutn()
    {
        return this->amount_;
    }



    private:
    double amount_;
    std::string name_;
 

};

class Paybal :public Bank
{
    public:
    Paybal(std::string name, double amount, std::string email):Bank( name, amount)
    {
        this->email_ = email;
    }

    void ProcessPayment() override
    {
        std::cout<<"Paypal Payment is processed"<<std::endl;
    }





    private:
    std::string email_;

};

class Creditcard : public Bank
{

    public:
    Creditcard(std::string name, double amount, int cardnum):Bank( name, amount)
    {
        this->cardnum = cardnum ;
    };

    void ProcessPayment() override
    {
         std::cout<<"Creditcard Payment is processing"<<std::endl;
       
    }



    private:
    int  cardnum;










};





















#endif
