// Question: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Serialize and Deserialize Binary Tree

// Approach: Make the bfs of the binary tree as storage string
// Use queue for bfs

class Codec {
public:
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string s = "";
        q.push(root);
        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            if (!ele) {
                s += "N ";
                continue;
            }
            s += to_string(ele->val) + ' ';
            q.push(ele->left);
            q.push(ele->right);
        }
        return s;
    }
    TreeNode* deserialize(string s) {
        vector<string> strs;
        string curr = "";
        for (char ele: s) {
            if (ele == ' ') {
              strs.push_back(curr);
              curr = "";
            }
            else {
              curr += ele;
            }
        }
        queue<TreeNode*> q;
        if (strs[0] == "N") return nullptr;
        auto ans = new TreeNode(stoi(strs[0]));
        q.push(ans);
        for (int i = 1; i < strs.size() - 1; i ++) {
          auto ele = q.front();
          q.pop();
          TreeNode* l, * r;
          if (strs[i] == "N") l = nullptr;
          else l = new TreeNode(stoi(strs[i]));
          i++;
          if (strs[i] == "N") r = nullptr;
          else r = new TreeNode(stoi(strs[i]));
          if (l) q.push(l);
          if (r) q.push(r);
          ele->left = l;
          ele->right = r;
        }
        return ans;
    }
};
