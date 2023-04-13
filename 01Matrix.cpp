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




// Question is same but need to find distance of nearest 1 instead of 0
// Approach 2: Using queue
// Make a queue of all 1's
// Apply BFS for all elements of queue at same time
// Add newly generated 1's to the queue
// All these elements will be at same distance(1 initially) from 1's
// Repeat with new 1's

vector<vector<int>>nearest(vector<vector<int>> arr)
{
    int r = arr.size(), c = arr[0].size();
    vector<vector<int>> ans(r, vector<int> (c, -1));
    queue<pair<int, int>> q;
    int dist = 1, zero = 0;
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j ++) {
            if (arr[i][j] == 1){
                q.push({i,j}); 
                ans[i][j] = 0;
            }
            else zero ++;
        }
    }
    while (!q.empty() && zero > 0) {
        int n = q.size();
        for (int x = 0; x < n; x ++) {
            auto curr = q.front();
            q.pop();
            vector<pair<int, int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
            for (auto ele: dir) {
                int row = curr.first + ele.first;
                int col = curr.second + ele.second;
                if (row < 0 || col < 0 || row >= r || col >= c || arr[row][col] == 1) 
                    continue;
                ans[row][col] = dist;
                arr[row][col] = 1;
                q.push({row, col});
                zero --;
            }
        }
        dist ++;
    }
    return ans;
}
