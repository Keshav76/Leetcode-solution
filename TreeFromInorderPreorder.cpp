// Question: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

// Construct Binary Tree from Preorder and Inorder Traversal

// Approach: Use 1st ele of preorder as root and divide the remaining part acc to left and right of inorder
// Make recursive call

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) return NULL;
    TreeNode* ans = new TreeNode(preorder[0]);
    int ind = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + ind + 1);
    vector<int> rightPreorder(preorder.begin() + ind + 1, preorder.end()); 
    vector<int> leftInorder(inorder.begin(), inorder.begin() + ind);
    vector<int> rightInorder(inorder.begin() + ind + 1, inorder.end());

    ans->left = buildTree(leftPreorder, leftInorder);
    ans->right = buildTree(rightPreorder, rightInorder);
    return ans;

}
