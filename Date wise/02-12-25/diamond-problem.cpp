/**
 * Program to demostrate the Diamond Problem in C++
 * The Diamond Problem occurs in multiple inheritance when two derived classes inherit from the same base class,
 * and a fourth class inherits from both derived classes. This can lead to ambiguity in accessing members of the base class.
 * To resolve this, C++ provides virtual inheritance.
 * In this example, we demonstrate the Diamond Problem and its resolution using virtual inheritance.
 */

#include <iostream>
using namespace std;
// Base class
class Base {
public:
    void show() {
        cout << "Base class show function called." << endl;
    }
};
// Derived class A inheriting from Base
class DerivedA : virtual public Base {
public:
    void showA() {
        cout << "DerivedA class showA function called." << endl;
    }
};
// Derived class B inheriting from Base
class DerivedB : virtual public Base {
public:
    void showB() {
        cout << "DerivedB class showB function called." << endl;
    }
};
// Derived class C inheriting from both DerivedA and DerivedB
class DerivedC : public DerivedA, public DerivedB {
public:
    void showC() {
        cout << "DerivedC class showC function called." << endl;
    }
};
int main() {
    DerivedC objC;
    objC.show();   // No ambiguity, Base class show function is called
    objC.showA();  // DerivedA class showA function is called
    objC.showB();  // DerivedB class showB function is called
    objC.showC();  // DerivedC class showC function is called
    return 0;
}