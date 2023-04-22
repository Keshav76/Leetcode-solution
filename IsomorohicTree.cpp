// Question: https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1

// Check If Tree is isomorphic

// Approach: Check isomorphic for t1->left, t2->left as well as t1->left, t2->right           for checking left isomorphism
// Same for right

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if (root1 == NULL && root2 == NULL) return true;
        if (root1 == NULL || root2 == NULL || root1->data != root2->data) return false;
        auto a1 = isIsomorphic(root1->left, root2->left) || isIsomorphic(root1->left, root2->right);
        auto a2 = isIsomorphic(root1->right, root2->left) || isIsomorphic(root1->right, root2->right);
        return a1 && a2;
    }
};
