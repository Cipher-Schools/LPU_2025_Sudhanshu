/**
 * Program to demonstrate the use of function templates in C++
 * This example defines a simple function template to find the sum of two values.
 * TC: O(1) for comparison operation.
 */

#include <iostream>
using namespace std;

template <typename T>
T findSum(T a, T b) {
    return a + b;
}

template <typename T>
T ConcatenateAndAdd(T a, T b) {
    return a + b;
}

int main() {

    int a = 10, b = 20;
    cout << "Sum of integers: " << ConcatenateAndAdd<int>(a, b) << endl;

    string str1 = "Hello, ", str2 = "World!";
    cout << "Concatenated string: " << ConcatenateAndAdd<string>(str1, str2) << endl;

    
    // Test with integers
    int int1 = 5, int2 = 10;
    cout << "Sum of integers: " << findSum(int1, int2) << endl;

    // Test with doubles
    double double1 = 5.5, double2 = 10.2;
    cout << "Sum of doubles: " << findSum(double1, double2) << endl;

    // Test with floats
    float float1 = 3.3f, float2 = 4.4f;
    cout << "Sum of floats: " << findSum(float1, float2) << endl;

    return 0;
}