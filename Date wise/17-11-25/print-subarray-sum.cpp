/**
 * Program to print all subarrays with their sum
 * Time Complexity: O(n^3)
 */

#include <iostream>
using namespace std;

void printSubarraySums(int arr[], int n) {
    for (int i = 0; i < n; i++) { // Starting index of subarray
        for (int j = i; j < n; j++) { // Ending index of subarray
            int sum = 0;
            // Calculate sum of subarray from index i to j
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            cout << "Sum of subarray from index " << i << " to " << j << " is: " << sum << endl;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "All subarrays with their sums are:" << endl;
    printSubarraySums(arr, n);
    
    return 0;
}