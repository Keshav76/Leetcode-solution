// Queestion: https://leetcode.com/problems/maximal-rectangle

// Maximal Rectangle

// Approach: Find height of histogram at each row -> if arr[row][col] = 0 : histHeight = 0; else histHeight = 1 + prevLayer

// Find max rectangle in each histogram

// return max

class Solution {
public:
    int maxHistogram(vector<char> arr) {
        int n = arr.size();
        vector<int> range(n, 0);
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i ++) {
            while (st.top()!= -1 && arr[st.top()] >= arr[i]) st.pop();
            range[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        st.push(n);
        for (int i = n-1; i >= 0; i --) {
            while (st.top()!= n && arr[st.top()] >= arr[i]) st.pop();
            range[i] = st.top() - range[i] - 1;
            st.push(i);
        }
        int mx = 0;
        for (int i = 0; i < n; i ++) {
            mx = max(mx, range[i] * (arr[i]+128));
        }
        return mx;
    }

    int maximalRectangle(vector<vector<char>>& arr) {
        int rows = arr.size(), cols = arr[0].size(), mx = 0;
        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (arr[i][j] == '1') arr[i][j] = -127;
                else arr[i][j] = -128;
            }
        }
        for (int i = 1; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (arr[i][j] == -127) arr[i][j] = arr[i-1][j] + 1;
            }
        }
        for (int i = 0; i < rows; i ++) {
            mx = max(mx, maxHistogram(arr[i]));
        }
        return mx;
    }
};
