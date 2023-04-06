// Question: https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/

// Infix to postfix

// Approach: Create a stack to hold lower priority 

string infixToPostfix(string s) {
    unordered_map<char, int> prec;
    prec['^'] = 3;
    prec['/'] = 2;
    prec['*'] = 2;
    prec['+'] = 1;
    prec['-'] = 1;
    stack<int> st;
    string ans = "";
    for(auto ele: s) {
        if (prec[ele] > 0) { // operator
            while (!st.empty() && prec[ele] <= prec[st.top()]) {
                ans += st.top();
                st.pop();
            }
            st.push(ele);
        }
        else if (ele == '(') {
            st.push(ele);
        }
        else if (ele == ')') {
            while (st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            ans += ele;
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
    // Your code here
}
