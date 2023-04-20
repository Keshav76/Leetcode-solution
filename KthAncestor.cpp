// Question: https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

// Kth Ancestor of a node

// Approach: DFS to first find the element
// then backtrack k steps 
// return val of that node

int findKthAncestor(Node *root, int target, int &k) {
    if (!root) return -1;
    if (root->data == target) {
        k--;
        return target;
    }
    int l = findKthAncestor(root->left, target, k);
    int r = findKthAncestor(root->right, target, k);
    if (l != -1 || r != -1) {
        if (k < 0) return max(l,r);
        k--;
        return root->data;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans = findKthAncestor(root, node, k);
    if (k >= 0) return -1;
    return ans;
}
