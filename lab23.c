#include <stdio.h>

void printArray(int a[], int n) {                           
    for(int i=0; i<n; i++)                              
        printf("%d ", a[i]);
    printf("\n");
}
void merge(int a[], int l, int m, int r, int *pass) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++) L[i] = a[l+i];
    for(int j=0; j<n2; j++) R[j] = a[m+1+j];            
    int i=0, j=0, k=l;
    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) a[k++] = L[i++];                
        else a[k++] = R[j++];
    }
    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];
    (*pass)++;
    printf("Pass %d: ", *pass);                          
    printArray(a, r+1);
}
void mergeSort(int a[], int l, int r, int *pass) {
    if(l < r) {
        int m = (l + r) / 2;                             
        mergeSort(a, l, m, pass);
        mergeSort(a, m+1, r, pass);
        merge(a, l, m, r, pass);
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements: ", n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);       
    int pass = 0;
    mergeSort(a, 0, n-1, &pass);
    printf("Sorted array: ");
    printArray(a, n);
    return 0;
}