// Question: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Top View of Binary Tree

// Approach: Line order BFS
// Keep track of line in which you are
// If no element has been found for that line add your element as it the topmost


vector<int> topView(Node *root)
{
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto top = q.front();
        auto ele = top.first;
        auto line = top.second;
        q.pop();
        if(ele->left) q.push({ele->left, line - 1});
        if(ele->right) q.push({ele->right, line + 1});
        if (mp.count(line) == 0) {
            mp[line] = ele->data;
        }
    }
    vector<int> ans;
    for (auto ele: mp) {
        ans.push_back(ele.second);
    }
    return ans;
}
