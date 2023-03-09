// Question: https://leetcode.com/problems/longest-repeating-character-replacement

// Lomgest Repeating Character Replacement

// Map + Sliding Window

class Solution {
public:
    bool isValid(int mp[], int k, int n) {
        int mx = 0;
        for (int i = 0; i < 26; i ++) mx = max(mp[i], mx);
        return n - mx <= k;
    }
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, currDiff = 0, ans = 0;
        int mp[26] = {0};
        for (j = 0; j < s.size(); j ++) {
            mp[s[j] - 'A'] ++;
            while (!isValid(mp, k, j - i + 1)) {
                mp[s[i] - 'A'] --;
                i ++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
