#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    
    // adjacency matrix
    int graph[101][101];

    // initialize
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    // fill edges
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
    }

    int dist[101];
    int visited[101] = {0};

    // initialize distance
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[k] = 0;

    // Dijkstra
    for (int i = 1; i <= n; i++) {
        int u = -1;
        int minDist = INF;

        // find min distance node
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        // relax edges
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // find max distance
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}