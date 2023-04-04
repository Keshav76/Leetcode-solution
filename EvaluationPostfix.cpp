// Question: https://www.geeksforgeeks.org/evaluation-of-postfix-expression/

// Evaluation of postfix expression

// Approach: Use stack

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto ele: tokens) {
            if (ele == "+" || ele == "-" || ele == "*" || ele == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (ele == "+") st.push(a+b);
                if (ele == "-") st.push(a-b);
                if (ele == "*") st.push(a*b);
                if (ele == "/") st.push(a/b);
            }
            else st.push(stoi(ele));
        }
        return st.top();
    }
};
