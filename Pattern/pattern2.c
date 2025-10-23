/*
Diamond Pattern in C
    * 
   * * 
  * * * 
 * * * * 
* * * * * 
 * * * * 
  * * * 
   * * 
    * 
     
*/
#include <stdio.h>
void main() {
    int n, i, j, space;

    printf("Enter the number of rows for the diamond pattern: ");
    scanf("%d", &n);

    // Upper half of diamond
    for(i = 0; i < n; i++) {
        // Print leading spaces
        for(space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        // Print stars
        for(j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // Lower half of diamond
    for(i = 1; i < n; i++) {
        // Print leading spaces
        for(space = 0; space < i; space++) {
            printf(" ");
        }
        // Print stars
        for(j = 0; j < n - i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}