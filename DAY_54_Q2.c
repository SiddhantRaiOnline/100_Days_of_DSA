#include <stdlib.h>

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int capacity = 10000;

    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

    struct TreeNode* queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    *returnSize = 0;

    int leftToRight = 1; // direction flag

    while (front < rear) {
        int size = rear - front;

        result[*returnSize] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[*returnSize] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            int index = leftToRight ? i : (size - 1 - i);
            result[*returnSize][index] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        leftToRight = !leftToRight; // flip direction
        (*returnSize)++;
    }

    return result;
}