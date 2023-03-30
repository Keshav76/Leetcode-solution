// QUestion: https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/

// Longest Possible Route in a Matrix with Hurdles

// Approach: Backtracking 
// Check in every direction and if you can find res (then and only then) update the ans;

pair<bool, int> solve(vector<vector<int>> arr, int i, int j, pair<int, int> req) {
    int r = arr.size(), c = arr[0].size();
    if (i < 0 || j < 0 || i >= r || j >= c) return {false, 0};
    if (arr[i][j] == 0) return {false, 0};
    if (i == req.first && j == req.second) return {true, 0};
    arr[i][j] = 0;
    int mx = -1;
    auto ans1 = solve(arr, i+1, j, req);
    auto ans2 = solve(arr, i-1, j, req);
    auto ans3 = solve(arr, i, j+1, req);
    auto ans4 = solve(arr, i, j-1, req);
    if (ans1.first) mx = max(mx, ans1.second);
    if (ans2.first) mx = max(mx, ans2.second);
    if (ans3.first) mx = max(mx, ans3.second);
    if (ans4.first) mx = max(mx, ans4.second);
    // return mx;
    if (mx == -1) return {false, 0};
    return {true, mx+1};
}

int findLongestPath(vector<vector<int>> arr, int s1, int s2, int e1, int e2) {
    auto ans = solve(arr, s1, s2, {e1,e2});
    return ans.second;
}
