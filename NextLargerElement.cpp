// Question: https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// Next Smaller Element

// Approach: Traverse from back
// Keep a stack for smallest numbers till now.
// If a larger number comes => while number is larger remove from stack
// i.e. you will get just bigger element in right


vector<long long> nextLargerElement(vector<long long> arr, int n){
    // Your code here
    stack<ll> st;
    vector<ll> ans(n, -1);
    for (ll i = n - 1; i >= 0; i --) {
        ll ele = arr[i];
        while (!st.empty() && st.top() <= ele) {
            st.pop();
        }
        if (st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(ele);
    }
    return ans;
}
