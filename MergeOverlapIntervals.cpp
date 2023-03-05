// Question: https://leetcode.com/problems/merge-intervals

// Merge Intervals

// Approach: Sort the intervals
// Increment time until it goes beyond ending point of previous ele

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i ++) {
            int first = arr[i][0];
            int second = arr[i][1];
            while (i < n  - 1 && arr[i+1][0] <= second) {
                second = max(second, arr[i+1][1]);
                i ++;
            }
            ans.push_back({first, second});
        }
        return ans;
    }
};
