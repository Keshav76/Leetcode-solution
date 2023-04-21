// Question: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

// Binary Tree to Doubly Linked List by inorder

// Approach: Whenver you find an element to be added add it to last of current linked list
// Make it doubly linked list later by traversal

class Solution {
public: 
    Node* ans, *temp;
    void dfs(Node* root) {
        if (!root) return;
        dfs(root->left);
        // todo
        temp->right = root;
        temp = root;
        dfs(root->right);
    }
    Node * bToDLL(Node *root){
        ans = new Node(-1);
        temp = ans;
        dfs(root);
        temp = ans->right;
        Node* prev = NULL;
        while (temp) {
            temp->left = prev;
            prev = temp;
            temp = temp->right;
        }
        return ans->right;
    }
};
