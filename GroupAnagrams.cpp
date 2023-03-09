// Question: https://leetcode.com/problems/group-anagrams

// Group Anagrams

// Approach: Map for each sorted string to its originating string

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (auto ele : strs) {
            auto temp = ele;
            sort(begin(ele), end(ele));
            mp[ele].push_back(temp);
        }  
        for (auto ele : mp) {
            ans.push_back(ele.second);
        }
        return ans;
    }
};
