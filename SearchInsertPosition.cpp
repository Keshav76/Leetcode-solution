//  Problem : https://leetcode.com/problems/search-insert-position

// Search Insert Position

// Approach: Simple binary search to find max element less than key
// return ans + 1;


class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1; 
        int ans = -1;
        while (l <= r) {
            int mid = l + (r-l) / 2;
            if (arr[mid] < target) {
                ans = mid; 
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans + 1;
    }
};
