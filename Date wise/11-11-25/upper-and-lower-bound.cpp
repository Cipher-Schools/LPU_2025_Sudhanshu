/*
    Program to find the lower and upper bound of a target element in a sorted array.
*/

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findLowerAndUpperBound(const vector<int>& arr, int target) {
    int lower = -1, upper = -1;
    int left = 0, right = arr.size() - 1;

    // Find lower bound
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            if (arr[mid] == target) lower = mid;
            right = mid - 1; // Continue searching in the left half
        } else {
            left = mid + 1;
        }
    }

    // Reset search boundaries for upper bound
    left = 0;
    right = arr.size() - 1;

    // Find upper bound
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            if (arr[mid] == target) upper = mid;
            left = mid + 1; // Continue searching in the right half
        } else {
            right = mid - 1;
        }
    }

    return {lower, upper};
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    pair<int, int> result = findLowerAndUpperBound(arr, target);
    cout << "Lower bound of " << target << " is at index: " << result.first << endl;
    cout << "Upper bound of " << target << " is at index: " << result.second << endl;

    return 0;
}