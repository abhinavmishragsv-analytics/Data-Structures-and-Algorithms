#include <stdio.h>

struct Edge {
    int u, v, w;
};
struct Edge edges[50], result[50];
int parent[20];
int n, e;
int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}
void unionSet(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    parent[pu] = pv;
}
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    int count = 0, totalCost = 0;
    printf("Edges in Kruskal MST:\n");
    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            result[count++] = edges[i];
            unionSet(u, v);
        }
    }
    for (int i = 0; i < count; i++) {
        printf("%d -- %d = %d\n", result[i].u, result[i].v, result[i].w);
        totalCost += result[i].w;
    }
    printf("Total Cost of MST = %d\n", totalCost);
    return 0;
}