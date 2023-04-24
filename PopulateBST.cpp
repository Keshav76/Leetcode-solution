// Question: https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

// Populate Inorder Successor for all nodes

// Approach: Keep a last visited counter and assign every node to last's next

class Solution
{
public:
    Node* temp = NULL;
    void populateNext(Node *root)
    {
        //code here
        if (!root) return;
        populateNext(root->left);
        if (temp) temp->next = root;
        temp = root;
        populateNext(root->right);
    }
};
