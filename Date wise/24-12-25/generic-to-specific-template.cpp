/**
 * Program to demonstrate a generic to specific template class function in C++.
 * The derived class uses a specific type for one of the template parameters.
 */

#include <iostream>
#include <typeinfo>
using namespace std;

// Base template class
template <typename T>
class Base {
public:
    void displayType() {
        cout << "Base class type: " << typeid(T).name() << endl;
    }
};

// Derived template class inheriting from Base with a specific type for T
template <typename T>
class Derived : public Base<T> {
public:
    void showType() {
        this->displayType(); // Call base class method
        cout << "Derived class specific type: int" << endl;
    }
    void combineAndDisplay(T a, int b) {
        cout << "Combined values: " << a << " and " << b << endl;
    }
};

int main() {
    Derived<double> obj; // Create an object of Derived with double type
    obj.showType(); // Display types
    obj.combineAndDisplay(10.5, 20); // Combine and display values

    Derived<string> obj2; // Create another object of Derived with string type
    obj2.showType(); // Display types
    obj2.combineAndDisplay("Hello", 65); // Combine and display values

    return 0;
}