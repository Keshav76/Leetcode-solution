// Question: https://leetcode.com/problems/container-with-most-water

// Container with most water

// Apporach: Two Pointer
// Alter that pointer which points to shorter bar

class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size(), i = 0, j = n - 1, ans = 0;
        while (i < j) {
            ans = max(ans, min(arr[i], arr[j]) * (j-i));
            if (arr[i] > arr[j]) j --;
            else i ++;
        }
        return ans;
    }
};
