// Question: https://leetcode.com/problems/3sum

// Three Sum

// Approach: Sort then two pointer approach for every ele

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        set<vector<int>> ans;
        for (int i = 0; i < n - 2 ; i ++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (arr[i] + arr[j] + arr[k] == 0)
                    ans.insert({arr[i], arr[j++], arr[k--]}); 
                else if (arr[i] + arr[j] + arr[k] > 0) k --;
                else j ++;
            }
        }
        vector<vector<int>> anss;
        for (auto ele: ans) {
            anss.push_back(ele);
        }
        return anss;
    }
};
