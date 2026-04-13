#include <stdlib.h>

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;

    if (root == NULL) return result;

    struct TreeNode* stack[1000];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct TreeNode* node = stack[top--];

        result[(*returnSize)++] = node->val;

        // Push right first (so left is processed first)
        if (node->right)
            stack[++top] = node->right;

        if (node->left)
            stack[++top] = node->left;
    }

    return result;
}