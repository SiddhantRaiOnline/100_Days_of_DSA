#include <stdlib.h>

// Find index in inorder
int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* build(
    int* inorder, int inStart, int inEnd,
    int* postorder, int* postIndex
) {
    if (inStart > inEnd)
        return NULL;

    // Pick current root from postorder
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[*postIndex];
    root->left = root->right = NULL;

    (*postIndex)--;

    // Find root in inorder
    int index = findIndex(inorder, inStart, inEnd, root->val);

    // Build RIGHT first
    root->right = build(inorder, index + 1, inEnd, postorder, postIndex);
    root->left  = build(inorder, inStart, index - 1, postorder, postIndex);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return build(inorder, 0, inorderSize - 1, postorder, &postIndex);
}