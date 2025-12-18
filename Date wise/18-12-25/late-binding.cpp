/**
 * Program to demonstrate the concept of late binding in C++.
 */

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function for sound
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
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

// Derived class: Cat
class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    // Base class pointer
    Animal* animal1;
    Animal* animal2;

    // Pointing to derived class objects
    animal1 = new Dog();
    animal2 = new Cat();

    // Late binding: function calls are resolved at runtime
    animal1->sound(); // Output: Dog barks
    animal2->sound(); // Output: Cat meows

    // Clean up
    delete animal1;
    delete animal2;

    return 0;
}