// Question: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

// Find All K-Distant Indices in an Array

// Approach
// Traverse in array
// If element is key check in range (i-k, i+k)
// also maintain j over entire iterations to keep ans unique

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> res;
    for (int i = 0, j = 0; i < nums.size(); ++i)
        if (nums[i] == key)
            for (j = max(j, i - k); j <= i + k && j < nums.size(); ++j)
                res.push_back(j);
    return res;
}
};
