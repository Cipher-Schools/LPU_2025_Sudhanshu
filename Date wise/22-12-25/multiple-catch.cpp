/**
 * Program to demonstrate multiple catch blocks in C++ for handling different types of exceptions.
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

void accessArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Array index out of bounds");
    }
    cout << "Element at index " << index << ": " << arr[index] << endl;
}

int main() {
    int num1, num2;
    cout << "Enter two integers (numerator and denominator): ";
    cin >> num1 >> num2;

    int arr[] = {10, 20, 30, 40, 50};
    int index;
    cout << "Enter an index to access in the array: ";
    cin >> index;

    try {
        int result = divide(num1, num2);
        cout << "Result: " << result << endl;

        accessArray(arr, 5, index);
    } catch (const runtime_error& e) {
        cerr << "Caught a runtime error: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cerr << "Caught an out of range error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Caught a general exception: " << e.what() << endl;
    }

    cout << "Program continues after exception handling." << endl;
    return 0;
}