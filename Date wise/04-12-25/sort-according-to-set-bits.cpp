/**
 * Program to sort according to the number of set bits in each integer
 * and then by the integer value itself if the number of set bits is the same.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count the number of set bits in an integer
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; // Increment count if the last bit is set
        n >>= 1;        // Right shift to check the next bit
    }
    return count;
}

int main() {
    // Create a vector of integers
    vector<int> numbers = {5, 3, 8, 1, 4, 7};

    // Sort the vector using a custom comparator
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        int setBitsA = countSetBits(a);
        int setBitsB = countSetBits(b);
        if (setBitsA == setBitsB) {
            return a < b; // If set bits are equal, sort by value
        }
        return setBitsA < setBitsB; // Otherwise, sort by number of set bits
    });

    // Print the sorted vector
    cout << "Sorted numbers according to set bits: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}