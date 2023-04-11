// Question: https://www.geeksforgeeks.org/sort-a-stack-using-recursion/

// Sort a stack using recursion

// Approach: Use recursion
// First pick all elements using call stack
// Keep Inserting in sorted order

// to insert in sorted order, again use recursion

#include <bits/stdc++.h> 
void pushInPlace(stack<int> &st, int num) {
	if (st.empty() || st.top() < num) {
		st.push(num);
		return;
	}
	int n = st.top();
	st.pop();
	pushInPlace(st, num);
	st.push(n);
}
void sortStack(stack<int> &st)
{
	// Write your code here
	if (st.empty()) {
		return;
	}
	int num = st.top();
	st.pop();
	sortStack(st);
	pushInPlace(st, num);
}
