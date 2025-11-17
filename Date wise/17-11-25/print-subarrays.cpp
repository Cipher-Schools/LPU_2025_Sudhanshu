/**
 * Print all subarrays of an array
 * Time Complexity: O(n^3)
 */

#include <iostream>
using namespace std;
void printSubarrays(int arr[], int n) {
    for (int i = 0; i < n; i++) { // Starting index of subarray
        for (int j = i; j < n; j++) { // Ending index of subarray
            // Print subarray from index i to j
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl; // New line after printing each subarray
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "All subarrays of the given array are:" << endl;
    printSubarrays(arr, n);
    
    return 0;
}
