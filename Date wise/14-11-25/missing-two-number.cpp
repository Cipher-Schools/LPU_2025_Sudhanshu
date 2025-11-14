/*
    Program to find two missing numbers in a given 1 to N numbers
*/

#include <iostream>
#include <cmath>
using namespace std;

void findMissingNumbers(int arr[], int n, int &missing1, int &missing2) {
    int totalSum = n * (n + 1) / 2; // Sum of first N natural numbers
    int totalSumSquares = n * (n + 1) * (2 * n + 1) / 6; // Sum of squares of first N natural numbers
    
    int sum = 0;
    int sumSquares = 0;
    
    for (int i = 0; i < n - 2; i++) {
        sum += arr[i]; // Sum of given numbers
        sumSquares += arr[i] * arr[i]; // Sum of squares of given numbers
    }
    
    int sumMissing = totalSum - sum; // Sum of the two missing numbers
    int sumSquaresMissing = totalSumSquares - sumSquares; // Sum of squares of the two missing numbers
    
    // Let the two missing numbers be x and y
    // We have:
    // x + y = sumMissing  ...(1)
    // x^2 + y^2 = sumSquaresMissing ...(2)
    // From (1), we can express y as y = sumMissing - x
    // Substituting in (2):
    // x^2 + (sumMissing - x)^2 = sumSquaresMissing
    // This simplifies to:
    // 2x^2 - 2*sumMissing*x + (sumMissing^2 - sumSquaresMissing) = 0
    
    int a = 2;
    int b = -2 * sumMissing;
    int c = sumMissing * sumMissing - sumSquaresMissing;
    
    int discriminant = b * b - 4 * a * c;
    
    int sqrtDiscriminant = static_cast<int>(sqrt(discriminant));
    
    missing1 = ( -b + sqrtDiscriminant ) / (2 * a);
    missing2 = sumMissing - missing1;
}

// brute force approach
void findMissingNumbersBruteForce(int arr[], int n, int &missing1, int &missing2) {
    bool present[n + 1] = {false};
    
    for (int i = 0; i < n - 2; i++) {
        present[arr[i]] = true;
    }
    
    missing1 = -1;
    missing2 = -1;
    
    for (int i = 1; i <= n; i++) {
        if (!present[i]) {
            if (missing1 == -1) {
                missing1 = i;
            } else {
                missing2 = i;
                break;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    
    int arr[n - 2];
    cout << "Enter " << n - 2 << " numbers (from 1 to " << n << "): ";
    for (int i = 0; i < n - 2; i++) {
        cin >> arr[i];
    }
    
    int missing1, missing2;
    findMissingNumbers(arr, n, missing1, missing2);
    cout << "The missing numbers are: " << missing1 << " and " << missing2 << endl;
    
    return 0;
}