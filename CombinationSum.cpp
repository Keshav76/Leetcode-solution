// Question: https://leetcode.com/problems/combination-sum/submissions/

// Combination Sum

// Approach: Backtracking
// Add one index or leave it
// If you add, you can add the same num again
// but if you leave once, you cant add it anymore

// Complexity: O(2^target)

class Solution {
public:
    void solve(vector<int> candidates, int target, int i, vector<int> &curr, int total, vector<vector<int>> &res) {
        if (i == candidates.size() || target < total) return;
        if (target == total) {
            res.push_back(curr);
            return;
        }
        curr.push_back(candidates[i]);
        solve(candidates, target, i, curr, total + candidates[i], res);
        curr.pop_back();
        solve(candidates, target, i + 1, curr, total, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> curr;
        solve(candidates, target, 0, curr, 0, res);
        return res;
    }
};
