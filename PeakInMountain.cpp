//Question: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

//Find Peak in Mountain Array

// eg:  3,7,12,"17",13,2,0

//Approach:
//Binary Search
// If arr[mid] < arr[mid+1]  (increasing) => start <- mid+1;
// Else => end <- mid;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size()-1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] < arr[mid+1]) start = mid+1;
            else  end = mid;
        }
        return start;
    }
};
