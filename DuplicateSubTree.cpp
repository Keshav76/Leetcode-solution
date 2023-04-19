// Question: https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

// Check if their is a Duplicate Sub Tree

// Approach: Do a dfs => and store all subtree's inorder traversal in a map
// If you ever find a pre existing inorder traversal return 1
// Else return 0

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    unordered_map<string, int> mp;
    pair<string, int> help(Node* root) {
        if (!root) return {"", 0};
        auto l = help(root->left), r = help(root->right);
        if (l.second || r.second) return {"", 1};
        if (l.first == "" && r.first != "") l.first='x';
        if (r.first == "" && l.first != "") r.first='x';
        string s = l.first + char(root->data + '0') + r.first;
        if (s.length()!=1 && mp[s]) {
            return {"", 1};
        }
        mp[s] = 1;
        return {s, 0};
    }
    int dupSub(Node *root) {
         // code here
         return help(root).second;
    }
};
