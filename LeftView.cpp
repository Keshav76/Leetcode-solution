// Question: Left View of a binary tree

// Left View

// Approach: BFS

vector<int> leftView(Node *root)
{
    if (!root) return {};
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
       int s = q.size();
       ans.push_back(q.front()->data);
       for (int i = 0 ; i < s; i ++) {
           auto top = q.front();
           q.pop();
           if (top->left) q.push(top->left);
           if (top->right) q.push(top->right);
       }
    }
    return ans;
}
