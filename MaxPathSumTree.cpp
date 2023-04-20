// Question: https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/

// Binary Tree Max Path Sum

// Approach: For path -> We can split on only one node
// So make a fn that returns no split solution
// And keep a global variable to store max of all split solutions
// Return that global variable

int ans;
class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = max(0, dfs(root->left));
        int r = max(0, dfs(root->right));
        ans = max(ans, l + r + root->val);
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};
