/*
    linear search- find index of an element in an array
*/

#include<stdio.h>
void main(){
    int n, i, key, found = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements of array: ");

    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i=0; i<n; i++){
        if(arr[i] == key){
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Element not found in the array\n");
    }
}