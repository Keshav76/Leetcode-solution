// Question: Search and insert in bst

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) 
        root->left = insert(root->left, val);
    else 
        root->right = insert(root->right, val);
    return root;
}
Node* search(Node* root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    if (root->val < val) return search(root->right, val);
    return search(root->right, val);
}
