// Question: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

// Diameter of a Binary Tree

// Approach : Calculate height and diameter of left and right subtree
// Return max d1, d2, (h1 + h2 + 1);



pair<int, int> helper(Node* root) {
    if (!root) return {0,0};
    auto a = helper(root->left), b = helper(root->right);
    return { max(max(a.first, b.first), a.second + b.second + 1), 
             max(a.second, b.second) + 1 }; 
}
int diameter(Node* root) {
    // Your code here
    return helper(root).first;
}
