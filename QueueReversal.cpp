// Question: https://practice.geeksforgeeks.org/problems/queue-reversal/1

// Queue Reversal

// Approach: Use stack and put all elements in it => then move it to queue


queue<int> rev(queue<int> q)
{
    stack<int> st;
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    return q;
    
}
