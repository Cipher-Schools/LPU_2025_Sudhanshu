/**
 * Resolving Ambiguity in Inheritance
 */
#include <iostream>
using namespace std;
// Base class
class A {
public:
    void sound() {
        cout << "A's sound." << endl;
    }
};

// Base class B 
class B {
public:
    void sound() {
        cout << "B's sound." << endl;
    }
};

// Derived class C inheriting from both A and B
class C : public A, public B {};

int main() {
    C objC;
    // objC.sound(); // This will cause ambiguity as both A and B have sound()
    objC.A::sound(); // Resolving ambiguity by specifying the class
    objC.B::sound(); // Resolving ambiguity by specifying the class
    return 0;
}