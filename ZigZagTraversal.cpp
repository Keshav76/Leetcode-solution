// Question: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

// Zig-Zag Order Traversal

// Approach: BFS with queue

class Solution{
    public:
    vector <int> zigZagTraversal(Node* root) {
    	vector<int> ans;
    	vector<int> curr;
    	queue<Node*> q;
    	q.push(root);
    	bool rev = false;
    	while (!q.empty()) {
    	    int s = q.size();
    	    for (int i = 0; i < s; i ++) {
    	        auto ele = q.front();
    	        q.pop();
    	        curr.push_back(ele->data);
    	        if (ele->left) q.push(ele->left);
    	        if (ele->right) q.push(ele->right);
    	    }
    	    if(rev) {
    	        reverse(curr.begin(), curr.end());
    	    }
    	    rev = !rev;
    	    ans.insert(ans.end(), curr.begin(), curr.end());
    	    curr = {};
    	}
    	return ans;
    }
};
