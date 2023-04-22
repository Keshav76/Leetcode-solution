// Question: https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

// Leaf at same level

// Approach: Make a boolean variable that will store if a leaf has already been found
// If after finding a leaf you goto a new level : return false

class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        bool foundLeaf = false;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            if (foundLeaf) return false;
            int s = q.size();
            for (int i = 0; i < s; i ++) {
                auto ele = q.front();
                q.pop();
                if (ele->left) q.push(ele->left); 
                if (ele->right) q.push(ele->right); 
                if (ele->left == NULL && ele->right == NULL) foundLeaf = true;
            }
        }
        return true;
    }
};
