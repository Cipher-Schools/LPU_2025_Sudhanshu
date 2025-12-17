/**
 * Program to demonstrate pure virtual functions in C++
 */
#include <iostream>
using namespace std;

// Base class
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
        cout << "Drawing Circle" << endl;
    }
};

// Derived class: Square
class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing Square" << endl;
    }
};

int main() {
    // Creating objects of derived classes
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    // Calling the draw function
    shape1->draw(); // Output: Drawing Circle
    shape2->draw(); // Output: Drawing Square

    // Cleaning up
    delete shape1;
    delete shape2;

    return 0;
}