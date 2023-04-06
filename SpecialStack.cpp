// Question: https://practice.geeksforgeeks.org/problems/special-stack/

// Special Stack

// Approach: Maintain a seperate stack for minimum element

stack<int> minn;
int curr = 0;
void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
	if (minn.empty() || minn.top() >= a) minn.push(a);
	curr ++;
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return curr == n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return curr == 0;
}

int pop(stack<int>& s){
	// Your code goes here
	curr --;
	int a = s.top();
	s.pop();
	if (minn.top() == a) minn.pop();
	return a;
}

int getMin(stack<int>& s){
	// Your code goes here
	return minn.top();
}
