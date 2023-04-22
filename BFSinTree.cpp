// Question: https://leetcode.com/problems/binary-tree-level-order-traversal/

// 102. Binary Tree Level Order Traversal

// Approach: BFS using queue

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans = {};
        vector<int> curr = {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (top == NULL) {
                if (!q.empty()) q.push(NULL);
                ans.push_back(curr);
                curr = {};
                continue;
            }
            curr.push_back(top->val);
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
        }
        return ans;
    }
};
