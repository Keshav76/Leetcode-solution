// Question: https://leetcode.com/problems/n-queens

// All N-Queeens

// Approach: Backtracking

bool isSafe(vector<string> &arr, int n, int r, int c) {
for (int i = 0; i < n; i ++) {
    if (arr[i][c] == 'Q' || arr[r][i] == 'Q') return false;
}
for (int i = 0; i < n; i ++) {
    if (r-i >= 0 && c+i < n && arr[r-i][c+i] == 'Q') return false;
    if (r-i >= 0 && c-i >= 0 && arr[r-i][c-i] == 'Q') return false;
    if (r+i < n && c+i < n && arr[r+i][c+i] == 'Q') return false;
    if (r+i < n && c-i >= 0 && arr[r+i][c+i] == 'Q') return false;
}
return arr[r][c] != 'Q';
}

void Nqueen(int n, vector<vector<string>> &res, vector<string> &curr, int i) {
if (i == n) {
    res.push_back(curr);
    return;
}
for (int ind = 0; ind < n; ind ++) {
    if (isSafe(curr, n, i, ind)) {
        curr[i][ind] = 'Q';
        Nqueen(n, res, curr, i+1);
        curr[i][ind] = '.';
    }
}
}

vector<vector<string>> solveNQueens(int n) {
vector<vector<string>> res;
string t = "";
for(int i = 0; i < n; i ++) t += '.';
vector<string> helper (n, t);
Nqueen(n, res, helper, 0);
return res;
}
