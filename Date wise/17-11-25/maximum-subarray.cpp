/**
 * Program to find the maximum subarray sum using Kadane's Algorithm
 * Time Complexity: O(n)
 */

#include <iostream>
using namespace std;
int maxSubarraySum(int arr[], int n) {
    int ans = arr[0]; 
    int cur = 0;

    for (int i = 0; i < n; i++) {
        cur += arr[i];

        if (ans < cur) {
            ans = cur;
        }

        if (cur < 0) {
            cur = 0;
        }
    }

    return ans;
}
int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, n);
    cout << "Maximum subarray sum is: " << maxSum << endl;

    return 0;
}