#include <stdio.h>
#include <stdlib.h>

#define MAX 100005
#define INF 1000000000

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

void addEdge(int u, int v, int w) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->v = v;
    n->w = w;
    n->next = adj[u];
    adj[u] = n;
}

struct HeapNode {
    int v, dist;
};

struct HeapNode heap[MAX];
int size = 0;

void swap(int i, int j) {
    struct HeapNode t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

void push(int v, int dist) {
    size++;
    heap[size].v = v;
    heap[size].dist = dist;

    int i = size;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(i, i/2);
        i /= 2;
    }
}

struct HeapNode pop() {
    struct HeapNode root = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (1) {
        int l = 2*i, r = 2*i+1, smallest = i;

        if (l <= size && heap[l].dist < heap[smallest].dist)
            smallest = l;
        if (r <= size && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if (smallest != i) {
            swap(i, smallest);
            i = smallest;
        } else break;
    }

    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int src;
    scanf("%d", &src);

    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        struct HeapNode cur = pop();
        int u = cur.v;
        int d = cur.dist;

        if (d > dist[u]) continue;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}