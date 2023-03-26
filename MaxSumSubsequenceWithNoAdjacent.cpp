// Question: https://leetcode.com/problems/house-robber/

// Maximum sum subsequence with no adjacent elements

// Approach: DP 
// dp[i] = max(dp[i-1], arr[i] + dp[i-2])
// dp[0] = arr[0]

class Solution {
public:
    int help(vector<int> arr, int i, unordered_map<int, int> &mp) {
        int n = arr.size();
        if (i >= n) return 0;
        if (mp.count(i)) return mp[i];
        mp[i] =  max(arr[i] + help(arr, i + 2, mp), help(arr, i + 1, mp));
        return mp[i];
    }
    int rob(vector<int>& nums) {
        unordered_map<int, int> mp;
        return help(nums, 0, mp);
    }
};
