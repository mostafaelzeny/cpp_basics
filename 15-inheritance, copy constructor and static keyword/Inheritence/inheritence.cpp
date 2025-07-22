//Inheritence an adding attributes to child class.

#include <iostream>

// Base class
class Robot {
protected:
    std::string name;
    int id;

public:
    Robot(std::string robotName, int robotId) : name(robotName), id(robotId) {
        std::cout << "Base Robot Constructor called\n";
    }

    void display() {
        std::cout << "Robot Name: " << name << ", ID: " << id << std::endl;
    }
};

// Derived class with additional attributes
class AdvancedRobot : public Robot {
private:
    int batteryLife; // New attribute

public:
    // Constructor that initializes both base and derived class attributes
    AdvancedRobot(std::string robotName, int robotId, int battery)
        : Robot(robotName, robotId), batteryLife(battery) { // Call base constructor
        std::cout << "AdvancedRobot Constructor called\n";
    }

    // New method to display extra attribute
    void displayAdvanced() {
        display(); // Call base class method
        std::cout << "Battery Life: " << batteryLife << " hours" << std::endl;
    }
};

int main() {
    AdvancedRobot ar("AI Bot", 101, 10); // Create an object with new attributes
    ar.displayAdvanced(); // Display both base and derived class attributes

    return 0;
}
