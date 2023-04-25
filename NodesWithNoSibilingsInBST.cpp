// Question: https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

// Print All Nodes that dont have sibiling

// Approach: Check if any element has only 1 child : that child will be in answer


vector<int> noSibling(Node* root)
{
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        auto ele = q.front();
        q.pop();
        if (ele->left && !ele->right) ans.push_back(ele->left->data);
        if (ele->right && !ele->left) ans.push_back(ele->right->data);
        if (ele->left) q.push(ele->left);
        if (ele->right) q.push(ele->right);
    }
    
    if (ans.size() == 0) return {-1};
    sort(ans.begin(), ans.end());
    return ans;
}
