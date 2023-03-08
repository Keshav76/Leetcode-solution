// Question: https://leetcode.com/problems/valid-palindrome

// Valid Palindrome

// Approach: Two Pointers

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i ++;
            while (i < j && !isalnum(s[j])) j --;
            if (isupper(s[i])) s[i] = s[i] - 'A' + 'a';
            if (isupper(s[j])) s[j] = s[j] - 'A' + 'a';
            if (s[i] != s[j]) return false;
            i ++; j --;
        }
        return true;
    }
};
