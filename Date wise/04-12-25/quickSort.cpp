// QuickSort program
/**
 * This program implements the QuickSort algorithm to sort an array of integers.
 * It includes functions for partitioning the array and recursively sorting the subarrays.
 
 * TC: O(n log n) on average, O(n^2) in the worst case
 * SC: O(log n) due to recursive stack space
 */

#include <iostream>
using namespace std;

int partition(int arr[], int first, int last)
{
    int i = first - 1, j = first;
    int pivot = arr[last];
    // for (; j < last; j++)
    while (j < last)
    {
        if (pivot > arr[j])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i + 1], arr[last]);

    return i + 1;
}
void quicksort(int arr[], int first, int last)
{
    if (first < last)
    {
        int pi = partition(arr, first, last);
        quicksort(arr, first, pi - 1);
        quicksort(arr, pi + 1, last);
    }
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    cout << "Quicksort: ";
    for (int &i : arr)
    {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}