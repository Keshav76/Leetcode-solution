// Question: https://leetcode.com/problems/spiral-matrix

// Spiral Matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
        int top = 0, left = 0, bot = arr.size() - 1, right = arr[0].size() - 1;
        while (top < bot && left < right) {
            for (int i = left; i < right; i ++) ans.push_back(arr[top][i]);
            for (int i = top; i < bot; i ++) ans.push_back(arr[i][right]);
            for (int i = right; i > left; i --) ans.push_back(arr[bot][i]);
            for (int i = bot; i > top; i --) ans.push_back(arr[i][left]);
            left ++;
            right --;
            top ++;
            bot --;
        }
        if (top == bot) for (int i = left; i <= right; i ++) ans.push_back(arr[top][i]);
        else if (left == right) for (int i = top; i <= bot; i ++) ans.push_back(arr[i][left]);
        return ans;
    }
};
