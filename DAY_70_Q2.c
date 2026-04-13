#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    
    int dist[101];

    // initialize
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    // relax edges k+1 times
    for (int i = 0; i <= k; i++) {
        int temp[101];

        // copy previous distances
        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int cost = flights[j][2];

            if (dist[u] != INF && dist[u] + cost < temp[v]) {
                temp[v] = dist[u] + cost;
            }
        }

        // update dist
        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }

    return dist[dst] == INF ? -1 : dist[dst];
}