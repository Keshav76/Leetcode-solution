// Question: https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// Find All Duplicates in an Array

// Approach: Set visited location to negative to mark as visited

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        for (int i = 0; i < n; i ++) {
            int ele = max(arr[i], -arr[i]) - 1;
            cout << ele << " ";
            if (arr[ele] < 0) ans.push_back(ele+1);
            arr[ele] = -arr[ele];
        }
        return ans;
    }
};
