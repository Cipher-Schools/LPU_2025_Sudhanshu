/*
    program to check if a string is a palindrome using recursion
*/

#include <stdio.h>
int isPalindrome(char str[], int start, int end) {
    // Base case: If there is only one character or no characters
    if (start >= end) {
        return 1; // It's a palindrome
    }
    // If the first and last characters do not match
    if (str[start] != str[end]) {
        return 0; // Not a palindrome
    }
    // Recursive call for the next pair of characters
    return isPalindrome(str, start + 1, end - 1);
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Calculate length of the string
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    if (isPalindrome(str, 0, length - 1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}