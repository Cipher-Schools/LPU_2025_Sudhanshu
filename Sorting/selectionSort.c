/*
    * Selection Sort Implementation in C
    * This code sorts an array of integers using the selection sort algorithm.
    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/
#include<stdio.h>
void main(){
    int n, i, j, min_idx, temp;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements of array: ");

    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(i=0; i<n-1; i++){
        // Find the minimum element in unsorted array
        min_idx = i;
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    printf("Sorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}