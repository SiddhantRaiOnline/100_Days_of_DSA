#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

struct Node {
    int v;
    struct Node* next;
};

struct Node* adj[MAXN];

int disc[MAXN], low[MAXN], visited[MAXN];
int timer;

int** result;
int* colSizes;
int resultSize;

void addEdge(int u, int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = adj[u];
    adj[u] = node;

    node = (struct Node*)malloc(sizeof(struct Node));
    node->v = u;
    node->next = adj[v];
    adj[v] = node;
}

void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timer;

    struct Node* temp = adj[u];

    while (temp) {
        int v = temp->v;

        if (v == parent) {
            temp = temp->next;
            continue;
        }

        if (!visited[v]) {
            dfs(v, u);

            if (low[v] < low[u])
                low[u] = low[v];

            if (low[v] > disc[u]) {
                result[resultSize] = (int*)malloc(2 * sizeof(int));
                result[resultSize][0] = u;
                result[resultSize][1] = v;
                colSizes[resultSize] = 2;
                resultSize++;
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }

        temp = temp->next;
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                         int* connectionsColSize, int* returnSize,
                         int** returnColumnSizes) {

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    timer = 0;
    resultSize = 0;

    result = (int**)malloc(connectionsSize * sizeof(int*));
    colSizes = (int*)malloc(connectionsSize * sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        addEdge(u, v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    *returnSize = resultSize;
    *returnColumnSizes = colSizes;

    return result;
}