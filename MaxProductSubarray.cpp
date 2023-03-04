// Question: https://leetcode.com/problems/maximum-product-subarray

// Maximum Product Subarray

// Approach: Maintain max and min till the point and update accordingly. Also check that max does'nt go below 1

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), mn = 1, mx = 1, ans = INT_MIN;
        for (int i = 0; i < n; i ++) {
            int tmp = mx;
            mx = max(max(mx * nums[i], mn * nums[i]), nums[i]);
            mn = min(min(tmp * nums[i], mn * nums[i]), nums[i]);
            ans = max(ans, mx);
            mx = max(1, mx);
            // mn = min(long(1), mn);
        }
        return ans;
    }
};
