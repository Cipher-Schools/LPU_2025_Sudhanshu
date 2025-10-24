/*
    Program to check if a number is a palindrome
*/
#include <stdio.h>
int main() {
    int num, originalNum, reversedNum = 0, remainder;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Reverse the number
    while (originalNum != 0) {
        remainder = originalNum % 10;
        reversedNum = reversedNum * 10 + remainder;
        originalNum /= 10;
    }

    // Check if the original number is equal to the reversed number
    if (reversedNum == num) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }

    return 0;
}