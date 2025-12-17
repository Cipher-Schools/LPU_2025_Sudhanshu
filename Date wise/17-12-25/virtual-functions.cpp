/**
 * Program to demonstrate virtual functions in c++.
 */

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
    virtual void info() {
        cout << "This is an animal" << endl;
    }

    // Virtual destructor
    virtual ~Animal() {}
};

// Derived class: Dog
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

int main() {
    // Creating objects of derived classes
    Animal* animal = new Dog();

    // Calling the sound function
    animal->sound(); // Output: Dog barks

    animal->info();  // Output: This is an animal

    // Cleaning up
    delete animal;

    return 0;
}