// Question: https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/

// BST to Balanced BST

// Approach: Store the inorder traversal (store the nodes not value) and make the balanced BST using middle value as root

void inorder(Node* root, vector<Node*> &v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}
Node *build(vector<Node*> &v, int l, int r) {
    if (l > r) return NULL;
    int mid = l + (r - l) / 2;
    Node *root = v[mid];
    root->left = build (v, l, mid-1);
    root->right = build (v, mid+1, r);
    return root;
}
Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<Node*> sorted;
    inorder(root, sorted);
    return build(sorted, 0, sorted.size() - 1);
}
