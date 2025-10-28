/*
    program to print fibonacci series up to n terms
*/
#include <stdio.h>

void printFibonacci(int n) {
    int a = 0, b = 1, c;
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
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