/*
    program to sum natural numbers up to n using recursion
*/

#include <stdio.h>
int sumNaturalNumbers(int n) {
    if (n <= 0) {
        return 0;
    } else {
        return n + sumNaturalNumbers(n - 1);
    }
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    int sum = sumNaturalNumbers(n);
    printf("Sum of natural numbers up to %d is %d\n", n, sum);
    return 0;
}