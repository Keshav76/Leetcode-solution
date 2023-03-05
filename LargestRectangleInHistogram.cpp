// Question: https://leetcode.com/problems/largest-rectangle-in-histogram

// Largest Rectangle in Histogram

// Approach: 

// Use Stack to store first smaller value on the left or right
// Calculate left and right ele with lesser value for all elements 
// Calculate area for every rectangle

//Maximize it

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int>  right(n);
        stack<int> st;
        st.push(n);
        for (int i = n - 1; i >= 0; i --) {
            while ( st.top() != n && arr[st.top()] >= arr[i]) st.pop();
            right[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        while (!st.empty()) st.pop();
        st.push(-1);
        for (int i = 0; i < n; i ++) {
            while ( st.top() != -1 && arr[st.top()] >= arr[i]) st.pop();
            int left = st.top();
            st.push(i);
            int curr = (right[i]) - (left+1);
            curr *= arr[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};
