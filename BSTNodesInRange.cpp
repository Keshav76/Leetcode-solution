// Question: https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

// Count BST nodes that lie in a given range

// Approach: DFS with a count variable

class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here
      if (!root) return 0;
      int count = getCount(root->left, l, h);
      count += getCount(root->right, l, h);
      if (root->data >= l && root->data <= h) count ++;
      return count;
    }
};
