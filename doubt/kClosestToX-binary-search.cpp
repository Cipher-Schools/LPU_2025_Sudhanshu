#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void kClosestToX(const int arr[], int n, int k, int x, int out[]) {
    int left = 0;
    int right = n - k;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x - arr[mid] < arr[mid + k] - x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    for (int i = 0; i < k; ++i)
        out[i] = arr[left + i];
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int k = 3;
    int x = 5;
    int result[k];

    kClosestToX(arr, sizeof(arr) / sizeof(arr[0]), k, x, result);

    cout << "The " << k << " closest elements to " << x << " are: ";
    for (int i = 0; i < k; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
