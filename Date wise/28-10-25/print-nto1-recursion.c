/*
    program to print n to 1 using recursion
*/

#include <stdio.h>
void printNTo1(int n) {
    if (n <= 0) {
        return;
    }
    printf("%d ", n);
    printNTo1(n - 1);
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Numbers from %d to 1 are:\n", n);
    printNTo1(n);
    printf("\n");
    return 0;
}