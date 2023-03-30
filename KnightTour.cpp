// Question: https://www.geeksforgeeks.org/the-knights-tour-problem/

// Knight Tour

// Approach: Backtracking and checking for every possible move (8 moves) for every cell in N*N grid

bool knightTour(int n, vector<vector<int>> &soln, int i = 0, int j = 0, int needed = 0) {
    if (needed == n * n) return true;
    if (i < 0 || j < 0 || i >= n || j >= n || soln[i][j] != -1) return false;
    vector<vector<int>> lol = {{-1,2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};
    soln[i][j] = needed;
    for (auto ele: lol) {
        if (knightTour(n, soln, i + ele[0], j + ele[1], needed+1)) return true;
    }
    soln[i][j] = -1;
    return false;
}
