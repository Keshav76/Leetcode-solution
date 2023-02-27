// Question: https://leetcode.com/problems/maximum-subarray/

// Maximum Subarray

//Approach: Kadane's

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int sum = INT_MIN, curr = 0;
        for (auto ele: arr) {
            curr += ele;
            sum = max(sum, curr);
            curr = max(0, curr);
        }
        return sum; 
    }
};
