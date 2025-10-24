/*
    Program to count the number of digits in a given integer
*/
#include <stdio.h>
int main() {
    int num, count = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Count the number of digits
    do {
        num /= 10;
        ++count;
    } while (num != 0);

    printf("Number of digits: %d\n", count);

    return 0;
}