// Question: https://www.geeksforgeeks.org/create-a-matrix-with-alternating-rectangles-of-0-and-x/

// Create a matrix with alternating O and X between circles

// Approach: Spiral Matrix

#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> alternateOX(int n, int m) {
    vector<vector<char>> ans(n, vector<char>(m,'A'));
    int t = 0, b = n-1, l = 0, r = m-1;
    char ele = 'X';
    while (t<b && l<r) {
        for (int i = l; i < r; i ++) ans[t][i] = ele;
        for (int i = t; i < b; i ++) ans[i][r] = ele;
        for (int i = r; i > l; i --) ans[b][i] = ele;
        for (int i = b; i > t; i --) ans[i][l] = ele;
        t ++;
        b --;
        l ++;
        r --; 
        if (ele == 'X') ele = 'O';
        else ele = 'X';
    }
    if (t == b) {
        for (int i = l; i <= r; i ++) ans[t][i] = ele;
    }
    else if (l == r) {
        for (int i = t; i <= b; i ++) ans[i][l] = ele;
    }
    return ans;
}

void print(vector<vector<char>> arr) {
    for (auto ele: arr) {
        for (auto e : ele) {
            cout << e << " ";
        }
        cout << "\n";
    }
}

int main() {
    auto ans = alternateOX(12,7);
    print(ans);
}
