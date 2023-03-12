// Question: https://leetcode.com/problems/palindromic-substrings

// Palindromic Substrings

// Approach: Expand from each element and pair of elements to search for palindromes and increment counter

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0, n = s.length();
        for (int i = 0; i < n; i ++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]){ count++; l --; r ++;}
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]){ count++; l --; r ++;}
        }
        return count;
    }
};
