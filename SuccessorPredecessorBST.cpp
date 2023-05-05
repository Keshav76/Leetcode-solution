// Question: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

// Find Successor and Predecessor

// Approach: Binary search while keeping record of pre and suc


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if (!root) return;

// Your code goes here
    if (root -> key == key) {
        auto p = root->left;
        while (p && p->right)p = p->right;
        
        auto s = root->right;
        while (s && s->left)s = s->left;
        if (p)
            pre = p;
        if (s)
        suc = s;
    }
    else if (root->key < key) {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}
