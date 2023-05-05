// Question: https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1

// Binary Tree to BST

// Approach : take all elements -> sort them -> place them in inorder

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    vector<int> nodes;
    int i = 0;
    void inorderGet(Node* root) {
        if (!root) return;
        inorderGet(root->left);
        nodes.push_back(root->data);
        inorderGet(root->right);
    }
    void inorderSet(Node* root) {
        if (!root) return;
        inorderSet(root->left);
        root->data = nodes[i++];
        inorderSet(root->right);
    }
    Node *binaryTreeToBST (Node *root) {
        //Your code goes here
        nodes = {};
        inorderGet(root);
        sort(nodes.begin(), nodes.end());
        i = 0;
        inorderSet(root);
        return root;
    }
};
