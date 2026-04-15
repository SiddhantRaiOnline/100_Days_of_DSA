#include <stdbool.h>
#include <stdlib.h>

void dfs(int** isConnected, int n, int city, bool* visited) {
    for (int j = 0; j < n; j++) {
        if (isConnected[city][j] == 1 && !visited[j]) {
            visited[j] = true;
            dfs(isConnected, n, j, visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    
    bool* visited = (bool*)calloc(n, sizeof(bool));
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(isConnected, n, i, visited);
            provinces++;  // new province found
        }
    }

    free(visited);
    return provinces;
}