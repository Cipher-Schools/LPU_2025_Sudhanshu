/**
 * Program to demonstrate the concept of concrete classes in C++.
 * concrete classes can be instantiated and used directly.
 * concrete classess connot have pure virtual functions.
 */

#include <iostream>
using namespace std;

// Concrete class
class Animal {
public:
    // Member function
    void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

int main() {
    // Creating an object of the concrete class
    Animal animal;

    // Calling the member function
    animal.sound(); // Output: Animal makes a sound

    return 0;
}