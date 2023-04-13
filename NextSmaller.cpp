// Question: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/

// Final Prices With a Special Discount in a Shop (Next Smaller)

// Approach: Use stack for storing small numbers from right in descending order


class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for (int i = n-1; i >= 0; i --) {
            int ele = arr[i];
            while (!st.empty() && ele < st.top()) {
                st.pop();
            }
            if (st.empty()) ans[i] = arr[i];
            else ans[i] = arr[i] - st.top();
            st.push(ele);
        }
        return ans;
    }
};
