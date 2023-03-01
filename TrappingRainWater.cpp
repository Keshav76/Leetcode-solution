// Question: https://leetcode.com/problems/trapping-rain-water

// Trapping Rain Water

// Approach: Make left and right array with max height bars on left and right side
// Check wether the both side has a bigger bar than yours and add the differnece to the answer

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<int> left(n), right(n);
        left[0] = 0;
        right[n-1] = 0;
        for (int i = 1; i < n; i ++) {
            left[i] = max(arr[i-1], left[i-1]);
        }
        for (int i = n - 2; i >= 0; i --) {
            right[i] = max(right[i+1], arr[i+1]);
        }
        for (int i = 0; i < n; i ++) {
            int water = min(left[i], right[i]) - arr[i];
            if (water > 0)
                ans += water;
        }
        return ans;
    }
};
