// Question: https://leetcode.com/problems/valid-parentheses

// Valid Parentheses

// Approach: Use Stack

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ele: s) {
            if (ele == '[' || ele == '{' || ele == '(')  {
                st.push(ele);
                continue;
            }
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if (
                ele == ')' && top != '(' || 
                ele == '}' && top != '{' || 
                ele == ']' && top != '['
            ) 
                return false;
        }
        return st.empty();
    }
};
