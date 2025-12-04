/**
 * Program to demonstrate the use of lambda functions
 * How to use in Sort, Find, and other STL algorithms
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Create a vector of integers
    vector<int> numbers = {5, 2, 8, 1, 4};

    // Sort the vector using a lambda function
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b; // Sort in ascending order
    });

    // Print the sorted vector
    cout << "Sorted numbers: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Find an element using a lambda function
    int target = 4;
    auto it = find_if(numbers.begin(), numbers.end(), [target](int num) {
        return num == target; // Check if the number matches the target
    });

    if (it != numbers.end()) {
        cout << "Found " << target << " in the vector." << endl;
    } else {
        cout << target << " not found in the vector." << endl;
    }

    return 0;
}