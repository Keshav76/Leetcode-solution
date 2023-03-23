// Question: https://leetcode.com/problems/set-matrix-zeroes/description/

// Set Matrix Zeroes

// Easy approach: copy matrix Space : O(mn)
// Better approach: use row and column array  Space: O(m+n)
// Best: use first row and column of matrix for storing the O(m + n) solution arrays.
// Edge condition: (0,0) -> repeated in both row and col : Use seperate variable for that


class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int r = arr.size(), c = arr[0].size(), row0 = 1, col0 = 1;
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                if (arr[i][j] == 0) {
                    if (i == 0) row0 = 0;
                    else arr[i][0] = 0;
                    if (j == 0) col0 = 0;
                    else arr[0][j] = 0;
                }
            }
        }
        cout << row0;
        for (int i = 1; i < c; i ++) {
            if (arr[0][i] == 0) {
                for (int j = 0; j < r; j ++) arr[j][i] = 0;
            }
        }
        for (int i = 1; i < r; i ++) {
            if (arr[i][0] == 0) {
                for (int j = 0; j < c; j ++) arr[i][j] = 0;
            }
        }
        if (row0 == 0) 
            for (int j = 0; j < c; j ++) arr[0][j] = 0;
        if (col0 == 0)
            for (int j = 0; j < r; j ++) arr[j][0] = 0;
    }
};
