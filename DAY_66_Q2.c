#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void addEdge(struct Node* adj[], int b, int a) {
    struct Node* temp = newNode(a);
    temp->next = adj[b];
    adj[b] = temp;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    struct Node* adj[numCourses];
    int indegree[numCourses];

    for (int i = 0; i < numCourses; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    // build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        addEdge(adj, b, a);
        indegree[a]++;
    }

    int queue[numCourses];
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        count++;

        struct Node* temp = adj[node];
        while (temp != NULL) {
            int neighbor = temp->data;
            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
                queue[rear++] = neighbor;

            temp = temp->next;
        }
    }

    return count == numCourses;
}