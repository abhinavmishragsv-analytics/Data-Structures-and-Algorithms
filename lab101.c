#include <stdio.h>

int graph[20][20], visited[20], n;
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 1; i <= n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
int main() {
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");
    return 0;
}
