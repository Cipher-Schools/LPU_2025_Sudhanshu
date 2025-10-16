/*
    insert element at a given position in an array
*/
#include<stdio.h>

void main(){
    int arr[100], n, i, element, pos;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter element to insert: ");
    scanf("%d", &element);

    printf("Enter position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    // Shift elements to the right
    for(i=n; i>pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    n++;

    printf("Array after insertion: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}