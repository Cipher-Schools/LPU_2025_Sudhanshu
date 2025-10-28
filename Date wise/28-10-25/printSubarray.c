/*
    print all subarrays of an array
*/
#include <stdio.h>
void printSubarrays(int arr[], int n) {
    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            // Print subarray from index start to end
            printf("Subarray from index %d to %d: ", start, end);
            for (int k = start; k <= end; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }
}
int main() {
    int arr[100];
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("All subarrays of the given array are:\n");
    printSubarrays(arr, n);

    return 0;
}