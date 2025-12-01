/**
 * Program to demonstrate order of constructor and destructor calls in multilevel inheritance.
 */

#include <iostream>
using namespace std;

// This example shows the order of constructor and destructor calls in multiple inheritance.
// Key rules:
// 1) Base class constructors run before the derived class constructor.
// 2) With multiple inheritance, base classes are constructed left-to-right as listed
//    in the inheritance list of the derived class.
// 3) Destructors run in the exact reverse order of construction.
// 4) Automatic (stack) objects are destroyed at the end of their scope; dynamically
//    allocated objects are destroyed when delete is called.

class B {
public:
    B()  { cout << "Constructor B" << endl; }
    ~B() { cout << "Destructor B"  << endl; }
};

class C {
public:
    C()  { cout << "Constructor C" << endl; }
    ~C() { cout << "Destructor C"  << endl; }
};

// D inherits from C first, then B.
// Construction order: C -> B -> D
// Destruction order:  D -> B -> C
class D : public C, public B {
public:
    D()  { cout << "Constructor D" << endl; }
    ~D() { cout << "Destructor D"  << endl; }
};

// E inherits from B first, then C to show the difference.
// Construction order: B -> C -> E
// Destruction order:  E -> C -> B
class E : public B, public C {
public:
    E()  { cout << "Constructor E" << endl; }
    ~E() { cout << "Destructor E"  << endl; }
};

int main() {
    cout << "Block with D (C then B as bases):" << endl;
    {
        D objD;
        // Expected:
        // Constructor C
        // Constructor B
        // Constructor D
    }
    // Expected after block ends:
    // Destructor D
    // Destructor B
    // Destructor C

    cout << "\nBlock with E (B then C as bases):" << endl;
    {
        E objE;
        // Expected:
        // Constructor B
        // Constructor C
        // Constructor E
    }
    // Expected after block ends:
    // Destructor E
    // Destructor C
    // Destructor B

    cout << "\nDynamic allocation (D):" << endl;
    D* p = new D();
    // Expected now (construction):
    // Constructor C
    // Constructor B
    // Constructor D

    cout << "Deleting dynamic D..." << endl;
    delete p;
    // Expected now (destruction):
    // Destructor D
    // Destructor B
    // Destructor C

    return 0;
}