// Question: https://leetcode.com/problems/longest-palindromic-substring

// longest Palindromic Substring

// Approach: expand from middle, and consider each element (and pair of adjacent elements : for even length palindrome) as center of palindrome

class Solution {
public:
    string longestPalindrome(string s) {
        int ansLen = 0, ansL, n = s.length();
        for (int i = 0; i < n; i ++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > ansLen) {
                    ansLen = r - l + 1;
                    ansL = l;
                }
                l --;
                r ++;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > ansLen) {
                    ansLen = r - l + 1;
                    ansL = l;
                }
                l --;
                r ++;
            }
        }
        return s.substr(ansL, ansLen);
    }
};
