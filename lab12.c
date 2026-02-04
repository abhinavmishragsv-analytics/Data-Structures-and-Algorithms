#include <stdio.h>

int main() {
    int c, first, last, middle, n, search, array[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers in SORTED order (Ascending):\n", n);
    for (c = 0; c < n; c++) {
        scanf("%d", &array[c]);
    }
    printf("Enter value to find: ");
    scanf("%d", &search);
    first = 0;
    last = n - 1;
    middle = (first + last) / 2;
    int iteration = 1;
    printf("\n--- Starting Binary Search ---\n");
    printf("Search Range: Indices %d to %d\n\n", first, last);
    while (first <= last) {
        printf("Iteration %d:\n", iteration);
        printf("  Current Range: [%d] to [%d]\n", first, last);
        printf("  Middle Index: %d, Value at Middle: %d\n", middle, array[middle]);
        if (array[middle] < search) {
            printf("  Result: %d is smaller than %d. Ignoring left half.\n", array[middle], search);
            first = middle + 1;
        } else if (array[middle] == search) {
            printf("  Result: MATCH FOUND!\n");
            printf("\n%d found at location %d.\n", search, middle + 1);
            break;
        } else {
            printf("  Result: %d is larger than %d. Ignoring right half.\n", array[middle], search);
            last = middle - 1;
        }
        middle = (first + last) / 2;
        iteration++;
        printf("--------------------------------------\n");
    }
    if (first > last) {
        printf("\n--- Search Complete ---\n");
        printf("Not found! %d isn't present in the list.\n", search);
    }
    return 0;
}