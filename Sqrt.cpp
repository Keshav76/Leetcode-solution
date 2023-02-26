// Question: https://leetcode.com/problems/sqrtx

//SQRT

// Approach: Binary Search for element just below or equal to the sqrt of given num

class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid <= x / mid) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};
