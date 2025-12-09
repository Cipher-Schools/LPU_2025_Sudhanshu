// note: adjustment class K24HR

/**
 * Program to demonstrate simple function overriding in C++
 */

#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base class show function called." << endl;
    }
};

class Derived : public Base {
public:
    void show() { // overriding Base::show
        cout << "Derived class show function called." << endl;
    }
};

int main() {
    Base b;
    Derived d;

    cout << "Calling show() on Base object:" << endl;
    b.show(); // Calls Base::show

    cout << "Calling show() on Derived object:" << endl;
    d.show(); // Calls Derived::show

    cout<< "Calling show() using Derived object using scope resolution:" << endl;
    d.Base::show(); // Calls Base::show using scope resolution

    return 0;
}