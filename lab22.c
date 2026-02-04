#include <stdio.h>

void print(int a[],int n){
    for(int i=0;i<n;i++) printf("%d ",a[i]);          
    printf("\n");
}
void insertionSort(int a[], int n) {
    int c=0,it=0;                                     
    for(int i=1;i<n;i++) {
        int key=a[i], j=i-1;
        int shifted=0;
        while(j>=0 && (++c && a[j]>key)) {             
            a[j+1]=a[j]; j--; shifted=1;
        }
        a[j+1]=key;                                   
        it++;
        printf("Pass %d: ",it); print(a,n);

    
        if(!shifted) break;
    }
    printf("Comparisons=%d Iterations=%d\n",c,it);        
}
int main() {
    int n; printf("Enter n: "); scanf("%d",&n);
    int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]);     
    insertionSort(a,n);
}