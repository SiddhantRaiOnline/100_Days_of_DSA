#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize); // store indices

    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {

        // If current temp is higher → resolve stack
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            result[idx] = i - idx;
        }

        // Push current index
        stack[++top] = i;
    }

    *returnSize = temperaturesSize;
    return result;
}