/*
    * bubbleSort.c
    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

#include<stdio.h>
void main(){
    int n, i, j, temp;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements of array: ");

    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}