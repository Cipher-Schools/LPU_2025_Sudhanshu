/**
 * Program to demonstrate the concept of abstract classes in C++.
 */
#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};

int main() {
    // Shape s; // Error: cannot instantiate abstract class

    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw(); // Output: Drawing a Circle
    shape2->draw(); // Output: Drawing a Rectangle

    delete shape1;
    delete shape2;

    return 0;
}