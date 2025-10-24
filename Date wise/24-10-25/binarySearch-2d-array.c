/*
    Program to perform binary search on a 2D array
*/
#include <stdio.h>
int binarySearch2D(int matrix[][100], int rows, int cols, int target) {
    int left = 0;
    int right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / cols][mid % cols];

        if (midValue == target) {
            return 1; // Target found
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0; // Target not found
}
int main() {
    int matrix[100][100];
    int rows, cols, target;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix (sorted row-wise and column-wise):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the target value to search: ");
    scanf("%d", &target);

    if (binarySearch2D(matrix, rows, cols, target)) {
        printf("Target %d found in the matrix.\n", target);
    } else {
        printf("Target %d not found in the matrix.\n", target);
    }

    return 0;
}