/*
    Search in Rotated Sorted Array
    Given a rotated sorted array and a target value, return the index of the target if found in the array, otherwise return -1.
*/

#include <iostream>
using namespace std;
int searchInRotatedSortedArray(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // To avoid potential overflow

        if (arr[mid] == key) {
            return mid; // Key found at index mid
        }

        // Determine which side is properly sorted
        if (arr[start] <= arr[mid]) { // Left side is sorted
            if (key >= arr[start] && key < arr[mid]) {
                end = mid - 1; // Search in the left half
            } else {
                start = mid + 1; // Search in the right half
            }
        } else { // Right side is sorted
            if (key > arr[mid] && key <= arr[end]) {
                start = mid + 1; // Search in the right half
            } else {
                end = mid - 1; // Search in the left half
            }
        }
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the element to search: ";
    cin >> key;

    int result = searchInRotatedSortedArray(arr, size, key);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}