/**
 * Program to demonstrate single inheritance in C++
 */
#include <iostream>
#include <string>
// ---------------------------------------------------------------
// 1) Single Inheritance    
// Base -> Derived
// Flowchart:
// [Base] ---> [Derived]
// Use-case: Extend a single base with new behavior.

class Base {
protected:
    int id;
public:
    Base(int id) : id(id) {}
};
class Derived : public Base {
    std::string name;
public:
    Derived(int id, const std::string& name) : Base(id), name(name) {}
};
void demo() {
    Derived d(1, "DerivedObject");
    std::cout << "Derived object created with id and name.\n";
}
// ---------------------------------------------------------------
// Best Practices:
// - Use single inheritance when a clear "is-a" relationship exists.
// - Keep base classes focused and minimal to avoid complexity.
// - Prefer composition over inheritance for code reuse when appropriate.
// - Ensure proper access specifiers (public/protected/private) for members.
// - Consider using virtual destructors in base classes if polymorphism is involved.
// ---------------------------------------------------------------
int main() {
    demo();
    return 0;
}