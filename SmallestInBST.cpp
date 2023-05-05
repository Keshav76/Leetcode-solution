// Question: https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1

// Minimum Element in BST

// Approach: Check the first element of inorder traversal
// Go as left as you can go

int minValue(Node* root) {
    // Code here
    if (!root) return -1;
    while (root->left) root = root -> left;
    return root->data;
}
