/*
    delete at beginning
*/

#include<stdio.h>

void main(){
    int arr[100], n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    // Delete element at beginning
    for(i=0; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    n--;

    printf("Array after deletion: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}