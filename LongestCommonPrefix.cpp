// Question: https://leetcode.com/problems/longest-common-prefix

// Longest Common Prefix

// Approach: Sort the strs array and check for all elements prefix

class Solution {
public:
    static bool compare(string a, string b) {
        return a.length() < b.length();
    }
    string longestCommonPrefix(vector<string>& s) {
        sort(s.begin(), s.end(), compare);
        for (auto ele : s) cout << ele << "\n";
        string ans = "";
        for (int i = 0; i < s[0].length(); i ++) {
            char ele = s[0][i];
            for (int j = 0; j < s.size(); j ++) {
                if (s[j][i] != ele) return ans;
            }
            ans += ele;
        }
        return ans;
    }
};
