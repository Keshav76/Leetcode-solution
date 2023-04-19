// Question: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// Boundary Traversal of Binary Tree

// Approach: Check in left subtree first => then for bottom check all leaf nodes => then for right subtree
// Also check for certain conditions to avoid repetition of certain characters

class Solution {
public:
    void lefti(Node* root, vector<int> &ans) {
        if (!root) return;
        ans.push_back(root->data);
        if (root->left) lefti(root->left, ans);
        else lefti(root->right, ans);
    }
    void bottom(Node* root, vector<int> &ans) {
        if (root->left) bottom(root->left, ans);
        if (root->right) bottom(root->right, ans);
        if (!root->left && !root->right) {
            ans.push_back(root->data);
        }
    }
    void righti(Node* root, vector<int> &ans) {
        if(!root) return;
        if (root->right) righti(root->right, ans);
        else righti(root->left, ans);
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        lefti(root->left, ans);
        if (root->left)
            ans.pop_back();
        bottom(root, ans);
        if (root->right || (!root->left))
            ans.pop_back();
        righti(root->right, ans);
        return ans;
    }
};
