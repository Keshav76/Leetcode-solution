// Question: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

// Diagonal Order Traversal

// Approach: Move to right for all elements in one level
// If any left ele appears push it to next level

vector<int> diagonal(Node *root) {
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    while (!q.empty()) {
        int s = q.size();
        for (int x = 0; x < s; x ++) {
            Node* temp = q.front();
            q.pop();
            while (temp) {
                if (temp->left) q.push(temp->left);
                ans.push_back(temp->data);
                temp = temp->right;
            }
        }
    }
    return ans;
}
