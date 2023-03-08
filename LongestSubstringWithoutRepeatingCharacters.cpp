// Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Longest Substring Without Repeating Characters

// Approach: Sliding Window + Map

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0; 
        map<char, int> mp;
        for (j = 0; j < s.size(); j ++) {
            cout << mp.count(s[j]);
            if (mp.count(s[j]) != 0 && mp[s[j]] >= i)  {
                i = mp[s[j]] + 1;
            }
            mp[s[j]] = j;
            ans = max (ans, (j-i+1));
        }
        return ans;
    }
};
