// Question: https://leetcode.com/problems/partition-equal-subset-sum/

// Partition Equal Subset Sum

// Approach: DP

/*

dp[x][0] = true;
dp[0][x] = false;
dp[i][j] = dp[i-1][j]                         // if j > arr[i-1]
dp[i][j] = dp[i-1][j] | dp[i-1][j-arr[i-1]]   // otherwise

*/

class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size(), sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += arr[i];
        }
        if (sum % 2) return false;
        sum /= 2;
        cout << sum;
        int dp[n+1][sum+1];
    	for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= sum; j ++) {
                if (j == 0) dp[i][j] = true;
                else if (i == 0) dp[i][j] = false;
                else if (j >= arr[i-1]) {
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-arr[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};
