/**
 * Program to demonstrate the use of new and delete operators in C++
 */
#include <iostream>
using namespace std;

int main() {
    // Dynamically allocate memory for an integer
    int* pInt = new int;
    *pInt = 42;
    cout << "Dynamically allocated integer value: " << *pInt << endl;

    // Deallocate the memory
    delete pInt;

    // Dynamically allocate memory for an array of integers
    int size = 5;
    int* pArray = new int[size];
    for (int i = 0; i < size; ++i) {
        pArray[i] = i * 10;
    }

    cout << "Dynamically allocated array values: ";
    for (int i = 0; i < size; ++i) {
        cout << pArray[i] << " ";
    }
    cout << endl;

    // Deallocate the array memory
    delete[] pArray;

    return 0;
}