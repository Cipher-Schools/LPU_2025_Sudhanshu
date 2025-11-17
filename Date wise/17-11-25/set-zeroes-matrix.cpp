/**
 * Program to set matrix rows and columns to zero if an element is zero
 * Time Complexity: O(m*n*(m+n)) (brute force)
 */

#include <iostream>
using namespace std;

// helper function to mark the row and column
void put(int** matrix, int m, int n, int row, int col) {
    for (int j = 0; j < n; j++) {
        if (matrix[row][j] != 0) matrix[row][j] = -1;
    }
    for (int i = 0; i < m; i++) {
        if (matrix[i][col] != 0) matrix[i][col] = -1;
    }
}

// function to set zeroes in the matrix
void setZeroes(int** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                put(matrix, m, n, i, j);
            }
        }
    }

    // finalize the matrix by converting -1 to 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) matrix[i][j] = 0;
        }
    }
}

int main() {
    int m = 3, n = 4;

    int** matrix = new int*[m];
    for (int i = 0; i < m; i++) matrix[i] = new int[n];

    int init[3][4] = {
        {1, 2, 0, 4},
        {5, 6, 7, 8},
        {9, 0, 11, 12}
    };
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = init[i][j];

    setZeroes(matrix, m, n);

    cout << "Matrix after setting zeroes:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }


    // delete allocated memory
    for (int i = 0; i < m; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}
