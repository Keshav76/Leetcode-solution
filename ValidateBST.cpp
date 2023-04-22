// Question: https://leetcode.com/problems/validate-binary-search-tree/submissions

// Validate Binary Search Tree

// Approach: Maintain a smallest and largest number to compare with the parent node
// Basic DFS

class Solution {
public:
    pair<pair<long, long>, bool> help(TreeNode* root) {
        if (!root) return {{0, 0},true};
        if (!(root->left || root->right)) return {{root->val, root->val}, true};
        auto l = help(root->left);
        auto r = help(root->right);
        if (!root->left) l = {{root->val, long(root->val)-1}, true};
        if (!root->right) r = {{long(root->val)+1, root->val}, true};

        if (!(l.second && r.second)) return {{0,0}, false};

        if (l.first.second < root->val && r.first.first > root->val) {
            return {{l.first.first, r.first.second}, true};
        }
        return {{0,0}, false};
    }
    bool isValidBST(TreeNode* root) {
        return help(root).second;
    }
};
