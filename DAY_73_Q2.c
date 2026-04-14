#define SIZE 1001

int parent[SIZE];

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union function
int unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb)
        return 0; // cycle detected

    parent[pa] = pb;
    return 1;
}

// Function required by platform
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    
    // Initialize parent
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }

    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (!unionSet(u, v)) {
            result[0] = u;
            result[1] = v;
        }
    }

    *returnSize = 2;
    return result;
}