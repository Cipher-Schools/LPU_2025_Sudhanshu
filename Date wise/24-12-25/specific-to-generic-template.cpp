/**
 * Progrmam to demonstrate a specific to generic template class inheritance in C++
 */

#include <iostream>
#include <typeinfo>
using namespace std;

// Base class with specific type
class Base {
public:
    void displayType() {
        cout << "Base class specific type: int" << endl;
    }
};

// Derived template class inheriting from Base
template <typename T>
class Derived : public Base {
public:
    void showType() {
        this->displayType(); // Call base class method
        cout << "Derived class generic type: " << typeid(T).name() << endl;
    }
    void combineAndDisplay(int a, T b) {
        cout << "Combined values: " << a << " and " << b << endl;
    }
};

int main() {
    Derived<double> obj; // Create an object of Derived with double type
    obj.showType(); // Display types
    obj.combineAndDisplay(10, 20.5); // Combine and display values

    Derived<string> obj2; // Create another object of Derived with string type
    obj2.showType(); // Display types
    obj2.combineAndDisplay(30, "Hello"); // Combine and display values

    return 0;
}