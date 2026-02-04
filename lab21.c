#include <stdio.h>

void print(int a[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void selectionSort(int a[], int n) {
    int c = 0, it = 0, flag;
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        flag = 0;
        for(int j = i + 1; j < n; j++, c++) {
            if(a[j] < a[min]) {
                min = j;
                flag = 1;
            }
        }
        if(flag) {
            int t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
        it++;
        printf("Pass %d: ", it);
        print(a, n);
        int sorted = 1;
        for(int k = 0; k < n - 1; k++)
            if(a[k] > a[k + 1]) { sorted = 0; break; }
        if(sorted) break;
    }
    printf("Comparisons = %d, Iterations = %d\n", c, it);
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    selectionSort(a, n);
    return 0;
}