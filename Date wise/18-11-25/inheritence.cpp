#include <iostream>
class Animal {
public:
    void makeSound() {
        std::cout << "Generic animal sound" << std::endl;
    }
};
class Dog : public Animal {
public:
    // Overriding the base class function
    void makeSound() {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.makeSound(); // Calls Dog's version: "Woof! Woof!"
    
    // To call the base version:
    myDog.Animal::makeSound(); // Calls Animal's version
    return 0;
}
