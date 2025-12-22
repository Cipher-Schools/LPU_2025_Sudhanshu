/**
 * Program to demonstrate the use of try-catch blocks in C++ for exception handling.
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

int main() {
    int num1, num2;
    cout << "Enter two integers (numerator and denominator): ";
    cin >> num1 >> num2;

    try {
        int result = divide(num1, num2);
        cout << "Result: " << result << endl;
    } catch (const runtime_error& e) {
        cerr << "Caught an exception: " << e.what() << endl;
    }

    cout << "Program continues after exception handling." << endl;
    return 0;
}