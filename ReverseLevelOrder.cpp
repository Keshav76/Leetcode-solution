// Question: https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

// Reverse Level Order Traversal

// Approach: Make a stack for keeping levels and then at last print in reverse order

vector<int> reverseLevelOrder(Node *root) {
    stack<vector<int>> v;
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (top == NULL) {
            v.push(ans);
            ans = {};
            if (!q.empty()) q.push(NULL);
            continue;
        }
        ans.push_back(top->data);
        if (top->left) q.push(top->left);
        if (top->right) q.push(top->right);
    }
    while (!v.empty()) {
        ans.insert(ans.end(), v.top().begin(), v.top().end());
        v.pop();
    }
    return ans;     
}
