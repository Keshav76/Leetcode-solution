// Question: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Kth Smallest Number

// Approach: Inorder Kth element

class Solution {
public:
    int mx, ans;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (mx-->0) ans = root->val;
        dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        mx = k;
        ans = 0;
        dfs(root);
        return ans;
    }
};
