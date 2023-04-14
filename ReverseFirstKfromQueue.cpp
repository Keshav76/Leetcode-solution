// Question: https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

// Reverse first K elements from queue

// Approach: use stack

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> st;
    queue<int> ans;
    for (int i = 0; i < k; i ++) {
        st.push(q.front());
        q.pop();
    }
    int i;
    for (i = 0; i < k; i ++) {
        ans.push(st.top());
        st.pop();
    }
    while (!q.empty()) {
        ans.push(q.front());
        q.pop();
    }
    return ans;
}
