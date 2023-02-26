// Question: https://leetcode.com/problems/first-bad-version/

// First Bad Version

//Approach: Binary Search
//Find minimum index of bad version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, ans = 0;
        while (l <= r) {
            int mid = l + (r-l) / 2;
            if (isBadVersion(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
