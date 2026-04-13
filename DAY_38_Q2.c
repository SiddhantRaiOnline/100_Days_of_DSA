#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int* dq = (int*)malloc(sizeof(int) * numsSize); // stores indices

    int front = 0, rear = -1;
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {

        // Remove out-of-window indices
        if (front <= rear && dq[front] <= i - k)
            front++;

        // Remove smaller elements from back
        while (front <= rear && nums[dq[rear]] < nums[i])
            rear--;

        // Add current index
        dq[++rear] = i;

        // Store result when window is valid
        if (i >= k - 1)
            result[idx++] = nums[dq[front]];
    }

    *returnSize = idx;
    return result;
}