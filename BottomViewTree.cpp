// Question: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/

// Bottom View of a tree

// Approach: Line order BFS

vector <int> bottomView(Node *root) {
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto top = q.front();
        auto ele = top.first;
        auto line = top.second;
        if (ele->left) q.push({ele->left, line-1});
        if (ele->right) q.push({ele->right, line+1});
        mp[line] = ele->data;
        q.pop();
    }
    vector<int> ans;
    for (auto ele: mp) ans.push_back(ele.second);
    return ans;
}
