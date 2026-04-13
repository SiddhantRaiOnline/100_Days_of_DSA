#include <stdio.h>
#include <stdlib.h>

// Pair structure
typedef struct {
    int val;
    int freq;
} Pair;

// Swap
void swap(Pair* a, Pair* b) {
    Pair t = *a;
    *a = *b;
    *b = t;
}

// Heapify down
void heapify(Pair heap[], int size, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < size && heap[l].freq < heap[smallest].freq)
        smallest = l;
    if (r < size && heap[r].freq < heap[smallest].freq)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

// Main function
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    // Step 1: Count frequency (simple array for range [-10000,10000])
    int freq[20001] = {0};

    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + 10000]++;
    }

    // Step 2: Min heap of size k
    Pair heap[k];
    int size = 0;

    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) {
            Pair p = {i - 10000, freq[i]};

            if (size < k) {
                heap[size++] = p;

                // heapify up
                int j = size - 1;
                while (j > 0 && heap[(j-1)/2].freq > heap[j].freq) {
                    swap(&heap[j], &heap[(j-1)/2]);
                    j = (j-1)/2;
                }
            }
            else if (p.freq > heap[0].freq) {
                heap[0] = p;
                heapify(heap, size, 0);
            }
        }
    }

    // Output
    int* result = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        result[i] = heap[i].val;
    }

    *returnSize = k;
    return result;
}