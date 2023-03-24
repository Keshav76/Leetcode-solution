// Question: https://www.geeksforgeeks.org/find-common-element-rows-row-wise-sorted-matrix/

// Find a common element in all rows of a given row-wise sorted matrix

// Approach: make a pointer for each row -> (it points the smallest element till now)

#include<bits/stdc++.h>
using namespace std;

int common(vector<vector<int>> grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<int> v(rows, 0); // show which column we are on right now in each row
    while (true) {
        int mn = 0;
        bool flag = true;
        for (int i = 0; i < rows; i ++) {
            if (grid[i][v[i]] < grid[mn][v[mn]]) {
                mn = i; flag = false;
            }
            else if (! (grid[i][v[i]] == grid[mn][v[mn]])) flag = false;
        }
        if (flag) return grid[mn][v[mn]];
        v[mn] ++;
        if (v[mn] == cols) break;
    }
    return -1;
}

int main() {
    vector<vector<int>> mat = { {1, 2, 3, 4, 5},{2, 4, 5, 8, 10},{3, 5, 7, 9, 11},{1, 3, 5, 7, 9},};
    cout << common(mat);
}
