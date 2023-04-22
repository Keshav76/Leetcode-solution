// Question: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

// Convert to sum tree

// Approach: find sum of left subtree and right subtree
// put value of their sum in root
// return initial root data + l + r

class Solution {
  public:
    int help(Node* root) {
        if (!root) return 0;
        int l = help(root->left), r = help(root->right);
        int temp = root->data;
        root->data = l + r;
        return temp + l + r;
    }
    void toSumTree(Node *root) {
        help(root);
    }
};
