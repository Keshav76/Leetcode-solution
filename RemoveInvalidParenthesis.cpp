// Question: https://leetcode.com/problems/remove-invalid-parentheses/description/

// Remove Invalid Parenthesis

// Approach: Find no of brackets required to remove to make it valid
// Recurse for all possible solution and when that much elements are removed, check for validity

class Solution {
public:
    int countWrong(string s) {
        stack<char> st;
        for (auto ele: s) {
            if (ele == '(') st.push(ele);
            else if (ele == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else st.push(ele);
            }
        }
        return st.size();
    }
    void solve(string s, vector<string> &ans, int rem, unordered_map<string,int> &mp) {
        if (mp[s] == 1) {return;}
        mp[s] = 1;
        if (rem == 0) {
            if (countWrong(s) == 0) {
                ans.push_back(s);
            }
            return;
        }
        for (int i = 0; i < s.length(); i ++) {
            auto left = s.substr(0,i);
            auto right = s.substr(i+1);
            solve(left + right, ans, rem - 1, mp);
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans = {};
        unordered_map<string, int> mp;
        solve(s, ans, countWrong(s), mp);
        return ans;
    }
};
