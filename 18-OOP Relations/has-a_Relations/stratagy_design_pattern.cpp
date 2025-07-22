#include <iostream>

// Step 1: Define the Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;  // Pure virtual function
    virtual ~PaymentStrategy() = default;
};

// Step 2: Implement Concrete Strategies
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid $" << amount << " using Credit Card.\n";
    }
};

class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid $" << amount << " using PayPal.\n";
    }
};

class CashPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid $" << amount << " using Cash.\n";
    }
};

// Step 3: Create the Context Class with Constructor Injection (No std::move)
class PaymentProcessor {
private:
    PaymentStrategy* strategy;  // Raw pointer (not owning)

public:
    PaymentProcessor(PaymentStrategy* chosenStrategy) : strategy(chosenStrategy) {}

    void processPayment(int amount) {
        if (strategy) {
            strategy->pay(amount);  // Call the selected payment method
        } else {
            std::cout << "No payment method selected!\n";
        }
    }
};

// Step 4: Use the Strategy Pattern in main()
int main() {
    CreditCardPayment creditCard;
    PayPalPayment paypal;
    CashPayment cash;

    PaymentProcessor creditCardProcessor(&creditCard);
    creditCardProcessor.processPayment(100);

    PaymentProcessor paypalProcessor(&paypal);
    paypalProcessor.processPayment(50);

    PaymentProcessor cashProcessor(&cash);
    cashProcessor.processPayment(20);

    return 0;
}
