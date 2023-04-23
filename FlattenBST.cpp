// Question: https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/

// Flatten binary search tree

// Approach: Inorder traversal

Node *temp;
void help(Node* root) {
    if (!root) return;
    help(root->left);
    temp->right = root;
    temp = temp->right;
    temp->left = NULL;
    help(root->right);
}
Node* flatten(Node* root) {
    auto head = new Node(-1);
    temp = head;
    help(root);
    return head->right;
}
