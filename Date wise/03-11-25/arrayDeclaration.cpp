/*
    Program to demonstrate how to declare and initialize arrays and multidimensional arrays in C++
*/

#include <iostream>
using namespace std;

int main() {
    // 1. Declaring and initializing a one-dimensional array
    int arr1[5] = {10, 20, 30, 40, 50};
    cout << "One-dimensional array elements:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "arr1[" << i << "] = " << arr1[i] << endl;
    }

    // 2. Declaring and initializing a two-dimensional array
    int arr2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "\nTwo-dimensional array elements:" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "arr2[" << i << "][" << j << "] = " << arr2[i][j] << endl;
        }
    }

    // 3. Declaring and initializing a three-dimensional array
    int arr3[2][2][2] = {
        {
            {1, 2},
            {3, 4}
        },
        {
            {5, 6},
            {7, 8}
        }
    };
    cout << "\nThree-dimensional array elements:" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                cout << "arr3[" << i << "][" << j << "][" << k << "] = " << arr3[i][j][k] << endl;
            }
        }
    }


    // 4. One-dimensional array using pointers (dynamic allocation)
    int n = 5;
    int* p1 = new int[n];
    for (int i = 0; i < n; ++i) {
        p1[i] = (i + 1) * 100; // putting some values
    }
    cout << "\nOne-dimensional array using pointers:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "p1[" << i << "] = " << p1[i] << endl;
    }
    delete[] p1;

    // 5. Two-dimensional array using pointers (array of pointers)
    int rows = 2, cols = 3;
    int** p2 = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        p2[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            p2[i][j] = (i + 1) * 10 + (j + 1);  // putting some values
        }
    }
    cout << "\nTwo-dimensional array using pointers:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "p2[" << i << "][" << j << "] = " << p2[i][j] << endl;
        }
    }
    for (int i = 0; i < rows; ++i) {
        delete[] p2[i];
    }
    delete[] p2;

    return 0;
}