#include <stdio.h>

#define MAX 1001

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    int front = 0, rear = 0;

    queue[rear++] = 1;
    visited[1] = 1;

    while (front < rear) {
        int node = queue[front++];

        for (int i = 1; i <= n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
}