// Question: https://leetcode.com/problems/4sum

// 4Sum

// Approach: Sort then two nested for loops then two pointer

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        for (int a = 0; a < n - 3; a ++) {
            if (a > 0 && arr[a] == arr[a-1]) continue;
            for (int b = a + 1; b < n - 2; b ++) {
                if (b > a+1 && arr[b] == arr[b-1]) continue;
                int c = b + 1, d = n - 1;
                while (c < d) {
                    if (arr[a] + long(arr[b]) + arr[c] + arr[d] == target) {
                        ans.push_back({arr[a], arr[b], arr[c], arr[d]});
                        c ++; d --;
                        while (c < d && arr[c] == arr[c - 1]) c ++;
                        while (d > c && arr[d] == arr[d + 1]) d --;
                    }
                    else if (arr[a] + long(arr[b]) + arr[c] + arr[d] > target) {
                        d --;
                    }
                    else {
                        c ++;
                    }
                }
            }
        }
        return ans;
    }
};
