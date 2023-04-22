// Question: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

// Check Balanced

// Approach: Check if left subtree is balanced + right subtree is balanced + -1 <= (left height - right height) <= 1

class Solution{
    public:
    pair<bool, int> help(Node* root) {
        if (!root) return {true, 0};
        auto l = help(root->left);
        auto r = help(root->right);
        return {(l.first && r.first && abs(l.second - r.second) <= 1 ), 
                max(l.second, r.second) + 1};
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return help(root).first;
    }
};
