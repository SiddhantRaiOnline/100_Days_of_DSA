int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int dist[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 100000;
        }
    }

    for (int i = 0; i < edgesSize; i++) {
        dist[edges[i][0]][edges[i][1]] = edges[i][2];
        dist[edges[i][1]][edges[i][0]] = edges[i][2];
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int ans = 0, min = 100000;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (i != j && dist[i][j] <= distanceThreshold)
                count++;

        if (count <= min) {
            min = count;
            ans = i;
        }
    }

    return ans;
}