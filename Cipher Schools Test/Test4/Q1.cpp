/*
    Program to find element in sorted array using Binary Search
*/

#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // To avoid potential overflow

        if (arr[mid] == key) {
            return mid; // Key found at index mid
        } 
        else if (arr[mid] < key) {
            start = mid + 1; // Search in the right half
        } 
        else {
            end = mid - 1; // Search in the left half
        }
    }
    return -1; // Key not found
}
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the element to search: ";
    cin >> key;

    int result = binarySearch(arr, size, key);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}