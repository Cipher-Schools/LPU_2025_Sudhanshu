/*
Constructor and Destructor Example in C++
This program demonstrates the use of a Constructor and Destructor
 in a C++ class.
*/

/*
Definition:
Constructor: Special member function sharing the class name, 
automatically invoked when an object is created. 
It initializes member variables or acquires resources. Has no return type.

Destructor: Special member function with the class name prefixed by '~', 
automatically invoked when an object is destroyed (scope end, delete, program termination). 
Used to release resources or perform cleanup. It has no return type and takes no parameters; 
only one destructor per class.
*/

#include <iostream>  // For std::cout and std::endl
using namespace std; // Use the standard namespace for brevity

// A simple class to demonstrate constructor and destructor behavior.
class Sample {
    int data;
    string info;

public:
    // Default constructor
    Sample() : data(0), info("Default") {
        cout << "Default constructor called. Data = " << data << ", Info = " << info << endl;
    }

    // Single-parameter constructor
    Sample(string value) : data(0), info("Parameterized") {
        cout << "Parameterized constructor called. Data = " << data << ", Info = " << info << endl;
    }

    // Constructor with default argument (overloaded)
    Sample(int value, int multiplier = 1) : data(value * multiplier) {
        cout << "Constructor (value, multiplier) called. Data = " << data << endl;
    }

    // Copy constructor
    Sample(const Sample& other) : data(other.data) {
        cout << "Copy constructor called. Data = " << data << endl;
    }

    ~Sample() {
        cout << "Destructor called. Data = " << data << endl;
    }

    void display() {
        cout << "Data = " << data << endl;
    }
};

int main() {
    Sample objDefault;              // Default constructor
    Sample objSingle(10);           // Single-parameter constructor
    Sample objWithDefaultArg(5);    // Uses (value, multiplier=1)
    Sample objOverloaded(5, 3);     // Uses overloaded constructor with multiplier
    Sample objCopy = objSingle;     // Copy constructor

    cout << "--- Displaying values ---" << endl;
    objDefault.display();
    objSingle.display();
    objWithDefaultArg.display();
    objOverloaded.display();
    objCopy.display();

    cout << "--- Scope test ---" << endl;
    {
        Sample temp(4, 2);
        temp.display();
    } // temp destroyed here

    return 0;
}