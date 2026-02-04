#include <stdio.h>

int main() {
    int arr[100], search, c, n;
    int found = 0;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (c = 0; c < n; c++) {
        scanf("%d", &arr[c]);
    }
    printf("Enter a number to search: ");
    scanf("%d", &search);
    printf("\n--- Starting Linear Search ---\n");
     for (c = 0; c < n; c++) {
        printf("Iteration %d: Checking index [%d]. Value is %d... ", c + 1, c, arr[c]);
        if (arr[c] == search) {
            printf("MATCH FOUND!\n");
            printf("\n%d is present at location %d.\n", search, c + 1);
            found = 1;
            break; 
        } else {
            printf("Not a match.\n");
        }
    }
    if (found == 0) {
        printf("\n--- End of Array Reached ---\n");
        printf("%d isn't present in the array.\n", search);
    }
    return 0;
}