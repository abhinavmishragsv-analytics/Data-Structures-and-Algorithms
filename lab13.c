#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int array[100], n, c, d, swap;
    int comparison_count = 0;
    int iteration_count = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (c = 0; c < n; c++) {
        scanf("%d", &array[c]);
    }
    printf("\n--- Original Array ---\n");
    printArray(array, n);
    printf("\n");
    for (c = 0; c < n - 1; c++) {
        printf("--- Pass %d ---\n", c + 1);
        int swapped = 0; 
        for (d = 0; d < n - c - 1; d++) {
            iteration_count++;
            comparison_count++;
            printf("  Compare index [%d](%d) and [%d](%d): ", d, array[d], d+1, array[d+1]);
            if (array[d] > array[d+1]) {
                printf("SWAP\n");
                swap = array[d];
                array[d] = array[d+1];
                array[d+1] = swap;
                swapped = 1;
                
                printf("  Current Array state: ");
                printArray(array, n);
            } else {
                printf("No Swap\n");
            }
        }
        printf("End of Pass %d. Array: ", c + 1);
        printArray(array, n);
        printf("\n");
        if (swapped == 0) {
            printf("Array is already sorted. Stopping early.\n\n");
            break;
        }
    }
    printf("--- Sorting Complete ---\n");
    printf("Sorted list in ascending order:\n");
    printArray(array, n);
    printf("\nStatistics:\n");
    printf("Total Comparisons: %d\n", comparison_count);
    printf("Total Inner Loop Iterations: %d\n", iteration_count);
    return 0;
}