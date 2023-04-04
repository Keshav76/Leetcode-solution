// Question: https://leetcode.com/problems/implement-stack-using-queues/

// Implement Stack using Queue

// Approach: Make push costly : Set the newes element at the top by inserting it at the bottom and 
// putting all values from above below it in a sequential manner

// Just like Stacking Pencil

class MyStack {
public:
    queue<int> q;
    int n;
    MyStack() {
        n = 0;
    }
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < n; i ++) {
            q.push(q.front());
            q.pop();
        }
        n ++;
    }
    
    int pop() {
        auto ans = q.front();
        q.pop();
        n --;
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return n == 0;
    }
};
