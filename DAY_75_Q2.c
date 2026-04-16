#include <stdbool.h>

bool dfs(int node, int color, int* colors, int** graph, int* graphColSize) {
    colors[node] = color;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];

        if (colors[neighbor] == -1) {
            if (!dfs(neighbor, 1 - color, colors, graph, graphColSize))
                return false;
        } 
        else if (colors[neighbor] == color) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int colors[graphSize];

    for (int i = 0; i < graphSize; i++) {
        colors[i] = -1; // uncolored
    }

    for (int i = 0; i < graphSize; i++) {
        if (colors[i] == -1) {
            if (!dfs(i, 0, colors, graph, graphColSize))
                return false;
        }
    }

    return true;
}