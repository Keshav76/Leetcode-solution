// Question: https://leetcode.com/problems/longest-valid-parentheses

// Longest Valid Parenthesis

// Approach: 
// 2 iteration (L to R) and (R to L)
// keep count of open and close brackets
// if condition becomes that you cant make a valid combination anymore
// then reset open and close 

class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, mx = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(') open ++;
            else close ++;
            if (open < close) {
                open = 0;
                close = 0;
            }
            else if (open == close) {
                mx = max(mx, open + close);
            }
        }
        open = 0, close = 0;
        for (int i = s.length() - 1; i >= 0; i --) {
            if (s[i] == '(') open ++;
            else close ++;
            if (open > close) {
                open = 0; 
                close = 0;
            }
            else if (open == close) {
                mx = max(mx, open + close);
            }
        }
        return mx;
    }
};
