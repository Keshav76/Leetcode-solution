// Question: https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Maximum depth of binary tree

// Approach: Calculate depth of left subtree then right subtree
// Find greater of two and add 1 to it

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
