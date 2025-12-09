// note: adjustment class K24HR

/**
 * Program to demonstrate function overriding in C++
 * with virtual functions and polymorphism
 */



#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { // virtual function
        cout << "Base class show function called." << endl;
    }
    virtual ~Base() = default; // virtual destructor
};

class Derived : public Base {
public:
    void show() override { // overriding Base::show
        cout << "Derived class show function called." << endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->show(); // Calls Derived::show due to virtual function
    basePtr->Base::show(); // Calls Base::show using scope resolution

    delete basePtr;
    return 0;
}