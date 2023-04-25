// Question: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Lowest common Ancestor of BST

// Approach: DFS acc to BST along with checking for split point

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        if (!root) return NULL;
        if (root->val <= q->val && root->val >= p->val) return root;
        if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        return lowestCommonAncestor(root->left, p, q);
    }
};
