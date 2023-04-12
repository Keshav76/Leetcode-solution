// Question: https://leetcode.com/problems/01-matrix/

// 01 Matrix

// Approach: DP
// First loop for left and up answers
// Second loop for right and bottom answers

// can't do all 4 in one loop as no way of going both direction at same time

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size(), max = r + c - 2;
        vector<vector<int>> ans (r, vector<int>(c, max));
        
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    continue;
                }
                int up = (i > 0) ? ans[i-1][j] : max;
                int left = (j > 0) ? ans[i][j-1] : max;
                ans[i][j] = min(up, left) + 1;
            }
        }
        
        for (int i = r - 1; i >= 0; i --) {
            for (int j = c - 1; j >= 0; j --) {
                int bottom = (i < r - 1) ? ans[i+1][j] : max;
                int right = (j < c - 1) ? ans[i][j+1] : max;
                ans[i][j] = min(ans[i][j], min(bottom, right) + 1);
            }
        }
        return ans;
    }
};
