/**
 * Program to demonstrate the use of C++ STL algorithms: sort, binary_search, and reverse.
 * TC: O(n log n) for sort, O(log n) for binary_search, O(n) for reverse
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {5, 2, 9, 1, 5, 6};

    // Sort
    sort(vec.begin(), vec.end());
    cout << "Sorted vector: ";
    for (const auto& v : vec) {
        cout << v << " ";
    }
    cout << endl;

    // Binary Search
    int target = 5;
    bool found = binary_search(vec.begin(), vec.end(), target);
    cout << "Element " << target << (found ? " found" : " not found") << " in the vector." << endl;

    // Reverse
    reverse(vec.begin(), vec.end());
    cout << "Reversed vector: ";
    for (const auto& v : vec) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}