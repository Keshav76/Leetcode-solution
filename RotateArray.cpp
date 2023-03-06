// Question: https://leetcode.com/problems/rotate-array

// Rotated Array

// Approach: 

// 1. Reverse whole array
// 2. Reverse first k elements
// 3. Reverse remaining elements

class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        k = k % arr.size();
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin()+k, arr.end());
    }
};
