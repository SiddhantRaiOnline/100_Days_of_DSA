#include <stdlib.h>

struct Map {
    struct Node* key;
    struct Node* value;
};

struct Map mp[1000];
int size = 0;

struct Node* get(struct Node* node) {
    for (int i = 0; i < size; i++) {
        if (mp[i].key == node)
            return mp[i].value;
    }
    return NULL;
}

void put(struct Node* key, struct Node* value) {
    mp[size].key = key;
    mp[size].value = value;
    size++;
}

struct Node* cloneGraph(struct Node* node) {
    if (!node) return NULL;

    struct Node* found = get(node);
    if (found) return found;

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    put(node, clone);

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneGraph(node->neighbors[i]);
    }

    return clone;
}