// Question: https://leetcode.com/problems/valid-perfect-square/

// Valid Perfect Solution

// Approach
// We need to search for a value in the range [1, n] that is a sorted array, so we can use binary search.
// Find largest ans with square less than or equal to num

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num, ans = 1;
        while (l <= r) {
            int i = l + (r - l) / 2;
            if (i <= num / i) {
                ans = i;
                l = i + 1;
            }
            else r = i - 1;
        }
        return ans * ans == num;
    }
};
