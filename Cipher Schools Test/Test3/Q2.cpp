/*
    Program to check if array is sorted and rotated.
*/
#include <iostream>
using namespace std;
bool isSortedAndRotated(int arr[], int n) {
    int count = 0; // Count of places where order breaks

    for (int i = 1; i < n; i++) {
        // Compare current element with the next element in a circular manner
        if (arr[i-1] > arr[i]) {
            count++;
        }
    }

    // Also check the last and first element
    if (arr[n-1] > arr[0]) {
        count++;
    }

    // If there is exactly one break, array is sorted and rotated
    return count <= 1;
}

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSortedAndRotated(arr, n)) {
        cout << "Array is sorted and rotated." << endl;
    } else {
        cout << "Array is not sorted and rotated." << endl;
    }

    return 0;
}
