// Question: https://leetcode.com/problems/surrounded-regions

// Surrounded Regions 

// DFS
// mark all O connected to corner as I
// and convert remaining O to X and I back to O

class Solution {
public:
    void setI(vector<vector<char>> &arr, int i, int j) {
        if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] != 'O') return;
        arr[i][j] = 'I';
        setI(arr, i+1, j);
        setI(arr, i-1, j);
        setI(arr, i, j+1);
        setI(arr, i, j-1);
    }
    void solve(vector<vector<char>>& arr) {
        int rows = arr.size(), cols = arr[0].size();
        for (int i = 0; i < cols; i ++) {
            setI(arr, 0, i);
            setI(arr, rows-1, i);
        }
        for (int i = 0; i < rows; i ++) {
            setI(arr, i, 0);
            setI(arr, i, cols-1);
        }
        
        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) { 
                if (arr[i][j] == 'I') arr[i][j] = 'O';
                else if (arr[i][j] == 'O') arr[i][j] = 'X';
            }
        }
    }
};
