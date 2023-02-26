//Question: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// To find first and last occurence of an element in an sorted array

//Approach: 
//Use Binary Search
//Divide question to two parts: First pos, Last pos
//For first pos, implement basic binary search with one extra condition
//Store ans whenever you find the key in array and then check in left part again for any more occurence

//Similarly for right most


class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1;
        int left = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                left = mid;
                end = mid-1;
            }
            else if (arr[mid] > target) end = mid-1;
            else start = mid+1;
        }
        start = 0;
        end = arr.size() - 1;
        int right = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                right = mid;
                start = mid+1;
            }
            else if (arr[mid] > target) end = mid-1;
            else start = mid+1;
        }
        return {left, right};
    }
};
