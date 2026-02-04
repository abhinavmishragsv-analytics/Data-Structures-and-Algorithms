#include <stdio.h>

int graph[20][20], visited[20], queue[20];
int n, front = 0, rear = -1;
void BFS(int start) {
    visited[start] = 1;
    queue[++rear] = start;
    while (front <= rear) {
        int v = queue[front++];  
        printf("%d ", v);
        for (int i = 1; i <= n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;  
            }
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
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);
    printf("BFS Traversal: ");
    BFS(start);
    printf("\n");
    return 0;
}
