// Question: https://leetcode.com/problems/number-of-islands

// Number of Islands

// Approach: Backtracking + DFS + clearing all connected part when we receive another island

class Solution {
public:
    void removeConnected(vector<vector<char>> &grid, int row, int col) {
        if (row >= grid.size() || 
            col >= grid[0].size() ||
            grid[row][col] == '0') 
        return;
        grid[row][col] = '0';
        removeConnected(grid, row+1, col);
        removeConnected(grid, row-1, col);
        removeConnected(grid, row, col+1);
        removeConnected(grid, row, col-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), count = 0;
        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (grid[i][j] == '1') {
                    removeConnected(grid, i, j); 
                    count++;
                }
            }
        }
        return count;
    }
};
