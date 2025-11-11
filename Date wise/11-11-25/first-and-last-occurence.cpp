/*
    Program to find first and last occurrence of an element in a sorted array.
*/

#include <iostream>
#include <vector>
using namespace std;
pair<int, int> findFirstAndLastOccurrence(const vector<int>& arr, int target) {
    int first = -1, last = -1;
    int left = 0, right = arr.size() - 1;

    // Find first occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            first = mid;
            right = mid - 1; // Continue searching in the left half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Reset search boundaries for last occurrence
    left = 0;
    right = arr.size() - 1;

    // Find last occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            last = mid;
            left = mid + 1; // Continue searching in the right half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return {first, last};
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    pair<int, int> result = findFirstAndLastOccurrence(arr, target);
    cout << "First occurrence of " << target << " is at index: " << result.first << endl;
    cout << "Last occurrence of " << target << " is at index: " << result.second << endl;

    return 0;
}