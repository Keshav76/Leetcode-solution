// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

// Min distance between two given nodes of a Binary Tree

// Approach: Find lowest common ancestor
// Find distance of each element from lca
// return sum of these distances;

class Solution{
    public:
    Node* lca(Node* root, int a, int b) {
        if (!root) return root;
        if (root->data == a || root->data == b) return root;
        auto l = lca(root->left, a, b), r = lca(root->right, a, b);
        if (l && r) return root;
        else if (l) return l;
        else return r;
    }
    int dist(Node* root, int a) {
        if (!root) return -1;
        if (root->data == a) return 0;
        int l = dist(root->left, a), r = dist(root->right, a);
        l = max(l, r);
        if (l == -1) return -1;
        return l + 1;
        
    }
    int findDist(Node* root, int a, int b) {
        Node* mid = lca(root, a, b);
        return (dist(mid, a) + dist(mid, b));
    }
};
