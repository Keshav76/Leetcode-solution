// Question: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

// Right View of Binary Tree

// Approach: BFS

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    
    vector<int> rightView(Node *root)
    {
        if (!root) return {};
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
           int s = q.size(), value = 0;
           for (int i = 0 ; i < s; i ++) {
               auto top = q.front();
               value = top->data;
               q.pop();
               if (top->left) q.push(top->left);
               if (top->right) q.push(top->right);
           }
           ans.push_back(value);
        }
        return ans;
    }
};
