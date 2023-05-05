// Question: https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

// Check wether bst has dead ends

// Approach: Traverse till each leaf and check if its predecessor and successor are just 1 apart from it

bool help(Node* root, Node* pre, Node* suc) {
    if (root->left == NULL && root->right == NULL) 
        return root->data - pre->data == 1 && suc->data - root->data == 1;
    bool l = false, r = false;
    if (root->left)
        l = help(root->left, pre, root);
    if (root->right)
        r = help(root->right, root, suc);
    return l || r;
}

bool isDeadEnd(Node *root)
{
    //Your code here
    help(root, new Node(0), new Node(0));
    
}
