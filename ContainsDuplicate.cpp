// Question: https://leetcode.com/problems/contains-duplicate

// Contains Duplicate

// Approach: Make a map that has all the visited values, if you find any value repeated => return true;

class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (auto ele: arr) {
            if (mp.count(ele)) return true;
            mp[ele] = 1;
        }
        return false;
    }
};
