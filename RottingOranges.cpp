// Question: https://leetcode.com/problems/rotting-oranges/

// Rotting Oranges

// Approach: Queue BFS at multiple levels
// BFS starts from every rotten orange at the same time
// After 1 step of all the BFS's is completed => Increment time spent by 1
// Now those older rotten oranges will no longer be used
// Newly generated rotten oranges will be used for BFS now


class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int r = arr.size(), c = arr[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, time = 0;
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                if (arr[i][j] == 1) fresh ++;
                else if (arr[i][j] == 2) q.push({i,j});
            }
        }
        while (!q.empty() && fresh > 0) {
            int n = q.size();
            for (int i = 0; i < n; i ++) {
                auto curr = q.front();
                q.pop();
                vector<pair<int, int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
                for (int j = 0; j < 4; j ++) {
                    int row = curr.first + dir[j].first;
                    int col = curr.second + dir[j].second;
                    if (row < 0 || row >= r || col < 0 || col >= c || arr[row][col] != 1) continue;
                    arr[row][col] = 2;
                    q.push({row, col});
                    fresh --;
                }
            }
            time ++;
        }
        return (fresh == 0 ? time : -1);
    }
};
