/*
    program to print 1 to n using recursion
*/

#include <stdio.h>
void print1ToN(int n) {
    if (n <= 0) {
        return;
    }
    print1ToN(n - 1);
    printf("%d ", n);
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Numbers from 1 to %d are:\n", n);
    print1ToN(n);
    printf("\n");
    return 0;
}