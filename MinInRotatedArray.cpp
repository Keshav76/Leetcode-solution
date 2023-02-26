// Question: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

//Find Minimum in rotated sorted array

//Approach
//Binary Search
//If mid is in left sorted portion check right
//else check left but including mid element as it might be mid

//Security Check at last: If your array is sorted then, this algo will return last element i.e. biggest element
// In that case return arr[0]

class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= arr[0]) start = mid + 1;
            else end = mid;
        }
        if (arr[start] > arr[0]) return arr[0];
        return arr[start];
    }
};
