/**
 * Program to demonstrate a generic to generic template class inheritance in C++.
 * The derived class uses different template parameters than the base class.
 */

#include <iostream>
using namespace std;

// Base template class
template <typename T>
class Base {
public:
    void displayType() {
        cout << "Base class type: " << typeid(T).name() << endl;
    }
};

// Derived template class inheriting from Base with a different type
template <typename T, typename U>
class Derived : public Base<T> {
public:
    void showTypes() {
        this->displayType(); // Call base class method
        cout << "Derived class type: " << typeid(U).name() << endl;
    }
    void combineAndDisplay(T a, U b) {
        cout << "Combined values: " << a << " and " << b << endl;
    }
};

int main() {
    Derived<int, double> obj; // Create an object of Derived with int and double types
    obj.showTypes(); // Display types
    obj.combineAndDisplay(10, 20.5); // Combine and display values

    Derived<string, char> obj2; // Create another object of Derived with string and char types
    obj2.showTypes(); // Display types
    obj2.combineAndDisplay("Hello", 'A'); // Combine and display values

    return 0;
}