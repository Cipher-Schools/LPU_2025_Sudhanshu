/**
 * Program to demonstrate rethrowing exceptions in C++.
 */

#include <iostream>
#include <stdexcept>

using namespace std;

int divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero error");
    }
    return a / b;
}

void performDivision(int a, int b) {
    try {
        int result = divide(a, b);
        cout << "Result: " << result << endl;
    } catch (const runtime_error& e) {
        cerr << "Caught an exception in performDivision: " << e.what() << endl;
        throw; // Rethrow the exception to be handled by the caller
    }
}

int main() {
    int num1, num2;
    cout << "Enter two integers (numerator and denominator): ";
    cin >> num1 >> num2;

    try {
        performDivision(num1, num2);
    } catch (const runtime_error& e) {
        cerr << "Caught a rethrown exception in main: " << e.what() << endl;
    }

    cout << "Program continues after exception handling." << endl;
    return 0;
}