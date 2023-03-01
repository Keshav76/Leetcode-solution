//Question: https://leetcode.com/problems/product-of-array-except-self/

// Product of Array Except Self

// Approach: cummulative multiple from both ends

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        left[0] = 1;
        for (int i = 1; i < n; i ++) {
            left[i] = left[i-1] * arr[i-1];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i --) {
            left[i] = left[i] * right;
            right *= arr[i];
        }
        return left;
    }

};
