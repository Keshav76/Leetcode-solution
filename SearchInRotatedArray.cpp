// Question: https://leetcode.com/problems/search-in-rotated-sorted-array

// Search in Rotated Sorted Array

// Approach: Binary Search

// Check if you are in left or right side
// Then make conditions to move left or right

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (arr[mid] == target) return mid;
            
            //Right Of Pivot
            if (arr[mid] < arr[0]) {
                if (target > arr[n-1] || target < arr[mid]) r = mid - 1;
                else l = mid + 1;
            }
            //Left of Pivot
            else {
                if (target > arr[mid] || target < arr[0]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
