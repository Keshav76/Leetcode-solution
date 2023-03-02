// Question: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

// Find Minimum in Rotated Sorted Array

// Approach: binary search

class Solution {
public:
    int findMin(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, ans = 0;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (arr[mid] >= arr[0]) {
                l = mid + 1;
            }
            else {
                ans = mid;
                r = mid - 1;
            }
        }
        return arr[ans];
    }
};
