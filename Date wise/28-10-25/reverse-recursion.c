/*
    program to reverse a string using recursion
*/
#include <stdio.h>
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }
    // Swap characters at start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call for the next pair
    reverseString(str, start + 1, end - 1);
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

    reverseString(str, 0, length - 1);
    printf("Reversed string: %s\n", str);
    return 0;
}