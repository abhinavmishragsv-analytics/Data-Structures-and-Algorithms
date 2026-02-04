#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
int partition(int arr[], int low, int high, int *comp, int *swaps, int n) {
    int pivot = arr[high], i = low - 1, temp;
    for (int j = low; j < high; j++) {
        (*comp)++;
        if (arr[j] < pivot) {
            i++;
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            (*swaps)++;
            printf("Swap %d: ", *swaps);
            printArray(arr, n);
        }
    }
    temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    (*swaps)++;
    printf("Pivot Swap %d: ", *swaps);
    printArray(arr, n);
    return i + 1;
}
void quickSort(int arr[], int low, int high, int *comp, int *iter, int *pass, int *swaps, int n) {
    if (low < high) {
        (*iter)++; (*pass)++;
        printf("\nIteration %d (Pass %d):\n", *iter, *pass);
        int pi = partition(arr, low, high, comp, swaps, n);
        printf("After Iteration %d: ", *iter);
        printArray(arr, n);
        quickSort(arr, low, pi - 1, comp, iter, pass, swaps, n);
        quickSort(arr, pi + 1, high, comp, iter, pass, swaps, n);
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int comp = 0, iter = 0, pass = 0, swaps = 0;
    printf("\nInitial array: ");
    printArray(arr, n);
    quickSort(arr, 0, n - 1, &comp, &iter, &pass, &swaps, n);
    printf("\nSorted array: ");
    printArray(arr, n);
    printf("\nComparisons: %d\nSwaps: %d\nPasses: %d\nIterations: %d\n",
           comp, swaps, pass, iter);
    return 0;
}