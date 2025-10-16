/*
    insert an element at the beginning of an array
*/
#include<stdio.h>

void main(){
    int arr[100], n, i, element;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter element to insert at beginning: ");
    scanf("%d", &element);

    // Shift elements to the right
    for(i=n; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = element;
    n++;

    printf("Array after insertion: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}