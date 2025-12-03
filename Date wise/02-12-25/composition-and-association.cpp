/**
 * Program to demonstrate composition and association in C++
 * Composition: A strong "has-a" relationship where the contained object cannot exist independently of the container object.
 * Association: A weaker "uses-a" relationship where the associated object can exist independently of the container object.
 */

#include <iostream>
#include <string>
using namespace std;
// Class representing an Engine (used in composition)
class Engine {
public:
    Engine(string type) : type(type) {}
    void start() {
        cout << "Engine of type " << type << " started." << endl;
    }
private:
    string type;
};

// Class representing a Car (composes an Engine)
class Car {
public:
    Car(string engineType) : engine(engineType) {}
    void start() {
        engine.start();
        cout << "Car started." << endl;
    }
private:
    Engine engine;
};

// Class representing a Driver (used in association)
class Driver {
public:
    Driver(string name) : name(name) {}
    void drive(Car &car) {
        cout << name << " is driving the car." << endl;
        car.start();     // Using the Car object
    }
private:
    string name;
};
int main() {
    Car myCar("V8");
    Driver driver("Alice");
    driver.drive(myCar);
    return 0;
}