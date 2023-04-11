// Question: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// Celebrity Problem

// Approach: 
// Trick is only 1 person can be celebrity 
// (bcoz if 2 person are celebrity => both wont know anyone 1st will not be known by 2nd)

// Make a stack and put all people in it
// Check the top two people 
// Whoever shows the sign of being a celebrity

// At last only 1 person will be left 
// check if he is a celebrity

int celebrity(vector<vector<int> >& M, int n) 
{
    // code here
    stack<int> st;
    for (int i = 0; i < n; i ++) {
        st.push(i);
    }
    while (st.size() > 1) {
        int f = st.top();
        st.pop();
        int s = st.top();
        st.pop();

        if (M[f][s]) st.push(s);
        else st.push(f);
    }
    int ans = st.top();
    for (int i = 0; i < n; i ++) {
        if ((i != ans && M[i][ans] == 0) || M[ans][i] == 1) return -1;
    }
    return ans;
}
