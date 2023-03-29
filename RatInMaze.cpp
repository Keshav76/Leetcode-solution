// Question: https://www.geeksforgeeks.org/rat-in-a-maze/

// Rat in a maze

// Approach: Backtracking

bool solve(vector<vector<int>> arr, int n, vector<vector<int>> &ans, int i, int j) {
    if (i >= n || j >= n) return false;
    if (i == -1 || j == -1) return false;
    if (i == n-1 && j == n-1) {
        ans[i][j] = 1;
        return true;
    }
    if (arr[i][j] == 0) return false;
    ans[i][j] = 1; arr[i][j] = 0;
    if (solve(arr, n, ans, i + 1, j)) return true;
    if (solve(arr, n, ans, i, j + 1)) return true;
    if (solve(arr, n, ans, i - 1, j)) return true;
    if (solve(arr, n, ans, i, j - 1)) return true;
    ans[i][j] = 0; arr[i][j] = 1;
    return false;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> arr) {
    int n = arr.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    solve(arr, n, ans, 0, 0);
    return ans;
}
