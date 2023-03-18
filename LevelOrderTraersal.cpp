// Question: Level Order Traversal

// https://leetcode.com/problems/binary-tree-level-order-traversal

// BFS



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while (!q.empty()) {

            auto qtop = q.front();
            q.pop();
            if (!qtop) {
                ans.push_back(temp);
                temp.clear();
                if (!q.empty()) q.push(NULL);
                continue;
            }
            temp.push_back(qtop->val);
            if (qtop->left) q.push(qtop->left);
            if (qtop->right) q.push(qtop->right);
        }
        return ans;
    }
};
