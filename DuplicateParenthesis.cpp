// Question: https://www.codingninjas.com/codestudio/problems/duplicate-parenthesis_2663296?leftPanelTab=1

// Duplicate Parenthesis

// Approach: Maintain a stack that will store all elements (other than closing braces)
// Whenever you enncounter a closing brace: check if there is any element betwwen just previous open bracket.
// IF NOT RETURN TRUE

bool duplicateParanthesis(string &expr)
{
    // Write your code here
    stack<char> st;
    for (char ele : expr) {
        if (ele != ')') st.push(ele);
        else {
            bool found = false;
            while (st.top() != '(') {
                found = true;
                st.pop();
            }
            st.pop();
            if (!found) return true;
        }
    }
    return false;
}
