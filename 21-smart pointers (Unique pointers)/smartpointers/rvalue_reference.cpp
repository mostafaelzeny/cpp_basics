#include <iostream>
#include <vector>

class Data {
public:
    std::vector<int> vec;
    Data() { vec = std::vector<int>(1000, 1); }

    Data(const Data& other) { // Copy constructor
        vec = other.vec;
        std::cout << "Copy Constructor Called\n";
    }

    Data(Data&& other) noexcept { // Move constructor
        vec = std::move(other.vec); // Transfers ownership
        std::cout << "Move Constructor Called\n";
    }
};

void process(Data d) {}

int main() {
    Data d1;
    process(std::move(d1)); // Calls Move Constructor (Efficient)
}
