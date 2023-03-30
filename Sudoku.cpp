// Question: https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587

// Sudoku

// Approach: For every empty spot try every possible move


bool isSafe(int arr[N][N], int r, int c, int num) {
        for (int i = 0; i < N; i ++) {
            if (arr[i][c] == num || arr[r][i] == num) return false;
        }
        int rr, cc;
        rr = (r / 3) * 3;
        cc = (c / 3) * 3;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (arr[i+rr][j+cc] == num) return false;
            }
        }
        return true;
    }
    bool solve(int arr[N][N], int i, int j) {
        if (i == N && j == 0) return true;
        int newi = i, newj = j + 1;
        if (j == N - 1) {newi = i + 1; newj = 0;}
        if (arr[i][j] != 0) return solve(arr, newi, newj);
        for (int num = 1; num <= N; num ++) {
            if (!isSafe(arr, i, j, num)) continue;
            arr[i][j] = num;
            if (solve(arr, newi, newj)) return true;
            arr[i][j] = 0;
        }
        return false;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        return solve(grid, 0, 0);
    }
