// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Best Time to buy and sell stock

//Approach: Maintain a buyPrice (min till now) and update maxProfit by checking profit at all indices

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size(), buyPrice = INT_MAX, maxProfit = INT_MIN;
        for (int i = 0; i < n; i ++) {
            buyPrice = min(buyPrice, arr[i]);
            maxProfit = max(maxProfit, arr[i] - buyPrice);
        }
        return maxProfit;
    }
};
