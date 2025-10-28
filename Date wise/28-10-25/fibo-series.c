/*
    program to print fibonacci series up to n terms
*/

#include <stdio.h>
void printFibonacci(int n) {
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    printf("Fibonacci Series: %d %d ", arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] +  arr[i - 2];
    }
    for (int i = 2; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);
    printFibonacci(n);
    return 0;
}