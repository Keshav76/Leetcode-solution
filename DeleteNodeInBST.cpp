// Question: https://leetcode.com/problems/delete-node-in-a-bst/

// Delete Node in BST

// Approach: There can be 3 cases 
// No children of the node to be removed => Simply remove the node
// 1 children => Make the children as the node 
// 2 children => Find the inorder successor of that element => Put its value in node to be deleted => Delete the successor (It will  be one of the 2 above cases)

class Solution {
public:
    TreeNode* succ(TreeNode* root) {
        if (!root) return NULL;
        if (!root->left) return root;
        return succ(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            if (!root->left) 
                return root->right;
            if (!root->right)
                return root->left;
            auto temp = succ(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
