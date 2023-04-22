// Question: https://leetcode.com/problems/invert-binary-tree/

// Invert Tree

// Approach: Swap the left subtree to right subtree along with recursion
// find the new left subtree and put it in right of your tree
// Same for right subtree => put it in left of your tree

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        auto l = invertTree(root->left);
        auto r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
};
