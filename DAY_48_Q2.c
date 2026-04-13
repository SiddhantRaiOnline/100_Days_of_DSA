int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) return 0;

    int sum = 0;

    // Check if left child is a leaf
    if (root->left && 
        root->left->left == NULL && 
        root->left->right == NULL) {
        
        sum += root->left->val;
    }

    // Recur on both sides
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}