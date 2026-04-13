#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *maxHeap; // left (max heap)
    int *minHeap; // right (min heap)
    int sizeMax, sizeMin;
    int capacity;
} MedianFinder;

// Swap
void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

// Max heapify up
void maxUp(MedianFinder* obj, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (obj->maxHeap[p] < obj->maxHeap[i]) {
            swap(&obj->maxHeap[p], &obj->maxHeap[i]);
            i = p;
        } else break;
    }
}

// Min heapify up
void minUp(MedianFinder* obj, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (obj->minHeap[p] > obj->minHeap[i]) {
            swap(&obj->minHeap[p], &obj->minHeap[i]);
            i = p;
        } else break;
    }
}

// Max heapify down
void maxDown(MedianFinder* obj, int i) {
    while (1) {
        int l = 2*i+1, r = 2*i+2, largest = i;
        if (l < obj->sizeMax && obj->maxHeap[l] > obj->maxHeap[largest]) largest = l;
        if (r < obj->sizeMax && obj->maxHeap[r] > obj->maxHeap[largest]) largest = r;
        if (largest != i) {
            swap(&obj->maxHeap[i], &obj->maxHeap[largest]);
            i = largest;
        } else break;
    }
}

// Min heapify down
void minDown(MedianFinder* obj, int i) {
    while (1) {
        int l = 2*i+1, r = 2*i+2, smallest = i;
        if (l < obj->sizeMin && obj->minHeap[l] < obj->minHeap[smallest]) smallest = l;
        if (r < obj->sizeMin && obj->minHeap[r] < obj->minHeap[smallest]) smallest = r;
        if (smallest != i) {
            swap(&obj->minHeap[i], &obj->minHeap[smallest]);
            i = smallest;
        } else break;
    }
}

// Create
MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));

    obj->capacity = 200000; // safe size
    obj->maxHeap = (int*)malloc(sizeof(int) * obj->capacity);
    obj->minHeap = (int*)malloc(sizeof(int) * obj->capacity);

    obj->sizeMax = 0;
    obj->sizeMin = 0;

    return obj;
}

// Add number
void medianFinderAddNum(MedianFinder* obj, int num) {

    // Step 1: push to maxHeap
    obj->maxHeap[obj->sizeMax++] = num;
    maxUp(obj, obj->sizeMax - 1);

    // Step 2: move top to minHeap
    int val = obj->maxHeap[0];
    obj->maxHeap[0] = obj->maxHeap[--obj->sizeMax];
    maxDown(obj, 0);

    obj->minHeap[obj->sizeMin++] = val;
    minUp(obj, obj->sizeMin - 1);

    // Step 3: balance sizes
    if (obj->sizeMin > obj->sizeMax) {
        int v = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->sizeMin];
        minDown(obj, 0);

        obj->maxHeap[obj->sizeMax++] = v;
        maxUp(obj, obj->sizeMax - 1);
    }
}

// Find median
double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->sizeMax > obj->sizeMin)
        return obj->maxHeap[0];
    else
        return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

// Free
void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}