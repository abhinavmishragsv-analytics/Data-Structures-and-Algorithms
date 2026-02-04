#include <stdio.h>

int cost[20][20], visited[20];
int n;
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost adjacency matrix (999 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    int edges = 0, totalCost = 0;
    visited[1] = 1; 
    printf("Edges in Prim MST:\n");
    while (edges < n - 1) {
        int min = 999, u = -1, v = -1;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        visited[v] = 1; 
        printf("%d -- %d = %d\n", u, v, min);
        totalCost += min;
        edges++;
    }
    printf("Total Cost of MST = %d\n", totalCost);
    printf("\n");
    return 0;
}
