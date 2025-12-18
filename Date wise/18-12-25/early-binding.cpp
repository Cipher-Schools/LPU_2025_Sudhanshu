/**
 * Program to demonstrate the concept of early binding in C++.
 */

#include <iostream>
using namespace std;

// Class with member function
class Calculator {
public:
    // Member function for addition
    int add(int a, int b) {
        return a + b;
    }

    // Member function for subtraction
    int subtract(int a, int b) {
        return a - b;
    }
};

int main() {
    // Creating an object of Calculator
    Calculator calc;

    // Early binding: function calls are resolved at compile time
    int sum = calc.add(10, 5);
    int difference = calc.subtract(10, 5);

    cout << "Sum: " << sum << endl;               // Output: Sum: 15
    cout << "Difference: " << difference << endl; // Output: Difference: 5

    return 0;
}