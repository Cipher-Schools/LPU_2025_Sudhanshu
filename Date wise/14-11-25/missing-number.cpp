/*
    Program to find the missing number in a given 1 to N numbers
*/

#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int total = n * (n + 1) / 2; // Sum of first N natural numbers
    int sum = 0;
    
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i]; // Sum of given numbers
    }
    
    return total - sum; // The missing number
}   

// brute force approach
int findMissingNumberBruteForce(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            return i; // The missing number
        }
    }
    return -1; // This should never happen if input is valid
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    
    int arr[n - 1];
    cout << "Enter " << n - 1 << " numbers (from 1 to " << n << "): ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    
    int missingNumber = findMissingNumber(arr, n);
    cout << "The missing number is: " << missingNumber << endl;
    
    return 0;
}