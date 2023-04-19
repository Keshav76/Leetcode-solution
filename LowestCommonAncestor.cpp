// Question: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

// Lowest Common Ancestor

// Approach: When you find an element return that else return null
// When you get somw answers from left and right return value of that node as it is merging point

Node* lca(Node* root ,int n1 ,int n2 ) {
   if (!root) return root;
   if (root->data == n1 || root->data == n2) return root;
   auto l = lca(root->left, n1, n2), r = lca(root->right, n1, n2);
   if (l && r) return root;
   else if (l) return l;
   else return r;
}
