/*
    Program to find the GCD of two numbers
*/
#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int rem = b;
        b = a % b;
        a = rem;
    }
    return a;
}
int main() {
    int num1, num2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    int result = gcd(num1, num2);
    printf("GCD of %d and %d is %d\n", num1, num2, result);

    return 0;
}