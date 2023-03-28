// Question: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

// Minimum Moves to Equal Array Elements II

// Approach: Find median of the array and convert all elements to this median

class Solution {
public:
    int minMoves2(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int n = arr.size(), mid, ans = 0;
        if(n % 2 == 0) mid = (arr[n/2] + arr[n/2 - 1])/2;
        else mid = arr[n/2];
        for (int i = 0; i < n; i ++) {
            ans += abs(mid - arr[i]);
        }
        return ans;
    }
};
