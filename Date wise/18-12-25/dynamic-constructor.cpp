/**
 * Program to demonstrate the concept of dynamic constructors in C++.
 */

#include <iostream>
using namespace std;

// Class with dynamic constructor
class Box {
private:
    double *length;
    double *width;
    double *height;
public:
    // Dynamic constructor
    Box(double l, double w, double h) {
        length = new double(l);
        width = new double(w);
        height = new double(h);
        cout << "Box created with dimensions: " 
             << *length << " x " << *width << " x " << *height << endl;
    }

    // Member function to calculate volume
    double volume() {
        return (*length) * (*width) * (*height);
    }

    // Destructor
    ~Box() {
        cout << "Box destroyed" << endl;
    }
};

int main() {
    // Creating an object of Box using dynamic constructor
    Box box1(3.5, 2.0, 4.0);
    cout << "Volume of box1: " << box1.volume() << endl;

    Box box2(5.0, 3.0, 2.0);
    cout << "Volume of box2: " << box2.volume() << endl;

    return 0;
}