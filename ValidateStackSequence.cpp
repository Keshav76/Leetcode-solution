// Question: https://leetcode.com/problems/validate-stack-sequences/description/

// Validate Stack Sequence

// Approach: Use a stack for keeping visited elemrnts.
// If at any point, st.top == needed[i] pop and i ++

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;  // popped index
        for (int i = 0; i < pushed.size(); i ++) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) {
                st.pop(); 
                j ++;
            }
        }
        while (!st.empty()) {
            if (popped[j] == st.top()) {
                st.pop();
                j ++;
            }
            else return false;
        }
        return true;
    }
};
