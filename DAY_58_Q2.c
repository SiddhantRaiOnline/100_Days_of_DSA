#include <stdlib.h>

// TreeNode is already defined on platforms like LeetCode

int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* build(
    int* preorder, int preStart,
    int* inorder, int inStart, int inEnd
) {
    if (inStart > inEnd)
        return NULL;

    // Create root
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];
    root->left = root->right = NULL;

    // Find root in inorder
    int index = findIndex(inorder, inStart, inEnd, root->val);

    // Number of nodes in left subtree
    int leftSize = index - inStart;

    // Build left and right
    root->left = build(preorder, preStart + 1, inorder, inStart, index - 1);
    root->right = build(preorder, preStart + 1 + leftSize, inorder, index + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return build(preorder, 0, inorder, 0, inorderSize - 1);
}