/**
 * Program to demonstrate virtual destructors in C++
 */

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base Constructor Called" << endl;
    }

    // Virtual destructor
    virtual ~Base() {
        cout << "Base Destructor Called" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived Constructor Called" << endl;
    }

    ~Derived() {
        cout << "Derived Destructor Called" << endl;
    }
};

int main() {
    Base* obj = new Derived();
    delete obj; // Correctly calls Derived's destructor followed by Base's destructor
    return 0;
}